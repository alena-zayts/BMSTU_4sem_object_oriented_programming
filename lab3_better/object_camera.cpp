#include "object_camera.hpp"

Camera::Camera(std::string name)
{
    position = Point<double>(0, 0, 300);
    this->name_ = name;
    this->x_angle = 0;
    this->y_angle = 0;
    this->z_angle = 0;
}

void Camera::Transform(const std::shared_ptr<Matrix<double>> mtr)
{
    position.Transform(mtr);
}

void Camera::Accept(std::shared_ptr<Visitor> visitor)
{
    visitor->Visit(*this);
}
