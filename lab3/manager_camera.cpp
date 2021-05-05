#include "manager_camera.hpp"

void CameraManager::TurnX(std::shared_ptr<Camera> camera, double angle)
{
    double cur_angle = camera->GetXAng();
    camera->SetXAng(angle / 180.0 * M_PI + cur_angle);
}

void CameraManager::TurnY(std::shared_ptr<Camera> camera, double angle)
{
    double cur_angle = camera->GetYAng();
    camera->SetYAng(angle / 180.0 * M_PI + cur_angle);
}

void CameraManager::TurnZ(std::shared_ptr<Camera> camera, double angle)
{
    double cur_angle = camera->GetZAng();
    camera->SetZAng(angle / 180.0 * M_PI + cur_angle);
}
