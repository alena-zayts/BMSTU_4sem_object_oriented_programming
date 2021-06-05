#ifndef LOAD_CONTROLLER_CAMERA_HPP
#define LOAD_CONTROLLER_CAMERA_HPP

#include "load_controller_base.hpp"
#include "builder_camera_base.hpp"
#include "camera_source_loader_base.hpp"

class CameraLoadController : public BaseLoadController
{
public:
    CameraLoadController(std::shared_ptr<BaseCameraBuilder> bld, std::shared_ptr<BaseCameraSourceLoader> source_loader);
    std::shared_ptr<SceneObject> load(std::string camera_name, std::string source_name) override;

private:
    std::shared_ptr<BaseCameraBuilder> builder_;
    std::shared_ptr<BaseCameraSourceLoader> source_loader_;
};

#endif // LOAD_CONTROLLER_CAMERA_HPP
