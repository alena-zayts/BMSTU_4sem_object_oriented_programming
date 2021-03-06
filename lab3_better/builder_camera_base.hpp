#ifndef BUILDER_CAMERA_BASE_HPP
#define BUILDER_CAMERA_BASE_HPP

#include "object_camera.hpp"

class BaseCameraBuilder
{
public:
    BaseCameraBuilder() = default;
    ~BaseCameraBuilder() = default;

    virtual void BuildPosition(const Point<double> centre) = 0;
    virtual void BuildAngles(const Point<double> angles) = 0;
    virtual void reset(std::string name) = 0;
    virtual std::shared_ptr<Camera> GetCamera() = 0;
};

#endif // BUILDER_CAMERA_BASE_HPP
