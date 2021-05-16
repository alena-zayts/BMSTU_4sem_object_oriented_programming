#include <ctime>

#include "error_drawer.hpp"
#include "matrix_transform.hpp"
#include "manager_draw.hpp"

void DrawManager::ProjectPoint(Point<double> &point)
{
    Point<double> cam_pos(camera_->GetPosition());

    // по z - потом
    std::shared_ptr<Matrix<double>> proj_matrix(std::make_shared<MoveMatrix>(-cam_pos.getX(), -cam_pos.getY(), 0));
    point.Transform(proj_matrix);

    proj_matrix.reset(new RotateOxMatrix(-camera_->GetXAng()));
    point.Transform(proj_matrix);

    proj_matrix.reset(new RotateOyMatrix(-camera_->GetYAng()));
    point.Transform(proj_matrix);

    proj_matrix.reset(new RotateOzMatrix(-camera_->GetZAng()));
    point.Transform(proj_matrix);

    double eps = 1e-10;
    double denom = point.getZ() + cam_pos.getZ();

    if (denom < eps && denom > -eps)
    {
        denom = eps;
    }

    double distCoef = cam_pos.getZ() / denom;

    point.setX(point.getX() * distCoef);
    point.setY(point.getY() * distCoef);
}

void DrawManager::SetDrawer(std::shared_ptr<BaseDrawer> drawer)
{
    drawer_ = drawer;
}

void DrawManager::SetCamera(std::shared_ptr<Camera> camera)
{
    camera_ = camera;
}

void DrawManager::Visit(Model &model)
{
    time_t t_time = time(NULL);

    if (!drawer_)
    {
        throw DrawerError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    if (!camera_)
    {
        throw CameraError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    auto carcass = model.GetCarcass();
    auto edges = carcass->GetEdges();

    for (auto &edge : edges)
    {
        ProjectPoint(edge.get_first());
        ProjectPoint(edge.get_second());
        drawer_->drawLine(edge.get_first(), edge.get_second());
    }
}

void DrawManager::Visit(Camera &camera) {}

void DrawManager::Visit(CompositeObject &comp) {}
