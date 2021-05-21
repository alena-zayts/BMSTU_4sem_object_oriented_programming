#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "drawer_base.hpp"
#include "loader_base.hpp"
#include "manager_draw.hpp"
#include "manager_scene.hpp"
#include "manager_transform.hpp"
#include "scene.hpp"

class Controller
{
public:
    // создавать извне не нужно
    Controller(Controller &) = delete;
    Controller(const Controller &) = delete;
    ~Controller() = default;

    static std::shared_ptr<Controller> GetInstance();

    SceneManager scene_manager_;
    TransformManager transform_manager_;
    std::shared_ptr<DrawManager> draw_manager_;
    std::shared_ptr<BaseLoadController> uploader_;

private:
    Controller();
};

#endif // CONTROLLER_HPP
