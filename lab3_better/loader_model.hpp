#ifndef LOADER_MODEL_HPP
#define LOADER_MODEL_HPP

#include "loader_base.hpp"

class ModelLoadController : public BaseLoadController
{
public:
    ModelLoadController(std::shared_ptr<BaseModelBuilder> bld);
    std::shared_ptr<SceneObject> load(std::string model_name, std::string source_name) override;
    void SetSourceLoader(std::shared_ptr<BaseModelSource> loader) override;

private:
    std::shared_ptr<BaseModelBuilder> builder_;
};

#endif // LOADER_MODEL_HPP
