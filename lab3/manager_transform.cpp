#include "manager_transform.hpp"
#include "matrix.hpp"

void TransformManager::MoveObject(std::shared_ptr<SceneObject> obj, int dx, int dy, int dz)
{
    std::shared_ptr<Matrix<double>> transform_matrix(std::make_shared<MoveMatrix>(dx, dy, dz));
    obj->Transform(transform_matrix);
}

void TransformManager::ScaleObject(std::shared_ptr<SceneObject> obj, double kx, double ky, double kz)
{
    std::shared_ptr<Matrix<double>> transform_matrix(std::make_shared<ScaleMatrix>(kx, ky, kz));
    obj->Transform(transform_matrix);
}

void TransformManager::RotateX(std::shared_ptr<SceneObject> obj, double angle)
{
    angle = DegToRad(angle);
    std::shared_ptr<Matrix<double>> transform_matrix(std::make_shared<RotateOxMatrix>(angle));
    obj->Transform(transform_matrix);
}

void TransformManager::RotateY(std::shared_ptr<SceneObject> obj, double angle)
{
    angle = DegToRad(angle);
    std::shared_ptr<Matrix<double>> transform_matrix(std::make_shared<RotateOyMatrix>(angle));
    obj->Transform(transform_matrix);
}

void TransformManager::RotateZ(std::shared_ptr<SceneObject> obj, double angle)
{
    angle = DegToRad(angle);
    std::shared_ptr<Matrix<double>> transform_matrix(std::make_shared<RotateOzMatrix>(angle));
    obj->Transform(transform_matrix);
}

double TransformManager::DegToRad(double angle)
{
    return angle / 180. * acos(-1.);
}
