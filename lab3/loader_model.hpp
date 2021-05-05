#ifndef LOADER_MODEL_HPP
#define LOADER_MODEL_HPP

#include "loader_base.hpp"

class ModelLoader : public BaseModelLoader
{
public:
    ModelLoader(std::shared_ptr<BaseSourceLoader> ldr, std::shared_ptr<BaseModelBuilder> bld);
    std::shared_ptr<Model> LoadModel(std::string model_name, std::string source_name) override;

private:
    std::shared_ptr<BaseModelBuilder> builder_;
};

#endif // LOADER_MODEL_HPP
