#ifndef DIRECTOR_CAMERA_HPP
#define DIRECTOR_CAMERA_HPP

#include <memory>

#include "builder_camera_base.hpp"
#include "camera_source_loader_base.hpp"
#include "object_camera.hpp"

class CameraDirector
{
public:
    std::shared_ptr<Camera> Build(const Point<double> position, const Point<double> angles);
    void SetBuilder(std::shared_ptr<BaseCameraBuilder> builder);

private:
    std::shared_ptr<BaseCameraBuilder> builder_;
};

#endif // DIRECTOR_CAMERA_HPP
