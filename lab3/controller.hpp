#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "drawer_base.hpp"
#include "loader_base.hpp"
#include "manager_camera.hpp"
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

    void AddModel(std::string model_name, std::string file_name);
    void AddCamera(std::string cam_name);

    void SetCamera(std::string cam_name);

    void RemoveModel(std::string model_name);
    void RemoveCamera(std::string cam_name);


    void TransformCamera(std::string cam_name, Point<double> &move, Point<double> &rotate);
    void TransformModel(std::string model_name, Point<double> &move, Point<double> &scale, Point<double> &rotate);

    void Draw(std::shared_ptr<BaseDrawer> drawer);

private:
    Controller();
    CameraManager camera_manager_;
    SceneManager scene_manager_;
    TransformManager transform_manager_;
    std::shared_ptr<DrawManager> draw_manager_;
    std::shared_ptr<BaseModelLoader> uploader_;
};

#endif // CONTROLLER_HPP
