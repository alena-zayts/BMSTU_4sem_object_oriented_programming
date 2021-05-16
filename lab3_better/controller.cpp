#include "controller.hpp"
#include "builder.hpp"
#include "loader_source_file.hpp"
#include "loader_model.hpp"
#include "error_scene.hpp"

Controller::Controller() : draw_manager_(std::make_shared<DrawManager>())
{
    std::shared_ptr<BaseModelBuilder> bld(std::make_shared<ModelBuilder>());
    std::shared_ptr<BaseModelLoader> uploader_(std::make_shared<ModelLoader>(bld));

    this->uploader_ = uploader_;
}

std::shared_ptr<Controller> Controller::GetInstance()
{
    static std::shared_ptr<Controller> instance_(new Controller());

    return instance_;
}

