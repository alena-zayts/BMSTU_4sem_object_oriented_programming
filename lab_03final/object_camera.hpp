#ifndef OBJECT_CAMERA_HPP
#define OBJECT_CAMERA_HPP

#include "matrix.hpp"
#include "visitor.hpp"
#include "object_invisible.hpp"
#include "point.hpp"

class Camera : public InvisibleObject
{
public:
    Camera(std::string name);

    void Transform(const std::shared_ptr<Matrix<double>> mtr);
    void Accept(std::shared_ptr<Visitor> visitor) override; // для visitor

    friend class DrawManager;
    friend class CameraBuilder;

private:
    Point<double> position;
    double x_angle;
    double y_angle;
    double z_angle;
};


#endif // OBJECT_CAMERA_HPP
