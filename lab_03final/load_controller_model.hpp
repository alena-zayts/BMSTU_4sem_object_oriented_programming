#ifndef LOADER_MODEL_HPP
#define LOADER_MODEL_HPP

#include "load_controller_base.hpp"

class ModelLoadController : public BaseLoadController
{
public:
    ModelLoadController(std::shared_ptr<BaseModelBuilder> bld, std::shared_ptr<BaseModelSourceLoader> source_loader);
    std::shared_ptr<SceneObject> load(std::string model_name, std::string source_name) override;

private:
    std::shared_ptr<BaseModelBuilder> builder_;
    std::shared_ptr<BaseModelSourceLoader> source_loader_;
};

#endif // LOADER_MODEL_HPP
