#ifndef BUILDER_CAMERA_HPP
#define BUILDER_CAMERA_HPP

#include <memory>

#include "builder_camera_base.hpp"
#include "camera_source_loader_base.hpp"

class CameraBuilder : public BaseCameraBuilder
{
public:
    CameraBuilder() = default;
    ~CameraBuilder() = default;

    void BuildPosition(const Point<double> centre) override;
    void BuildAngles(const Point<double> angles) override;
    void reset(std::string name) override;
    std::shared_ptr<Camera> GetCamera() override;

private:
    std::shared_ptr<Camera> camera;
};

#endif // BUILDER_CAMERA_HPP
