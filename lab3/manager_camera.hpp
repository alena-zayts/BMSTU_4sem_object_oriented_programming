#ifndef MANAGER_CAMERA_HPP
#define MANAGER_CAMERA_HPP

#include <math.h>
#include "manager_base.hpp"
#include "scene.hpp"

class CameraManager : public BaseManager
{
public:
    void TurnX(std::shared_ptr<Camera> camera, double angle);
    void TurnY(std::shared_ptr<Camera> camera, double angle);
    void TurnZ(std::shared_ptr<Camera> camera, double angle);
};


#endif // MANAGER_CAMERA_HPP
