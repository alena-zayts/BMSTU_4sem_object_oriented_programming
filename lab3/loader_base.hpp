#ifndef LOADER_BASE_HPP
#define LOADER_BASE_HPP

#include <memory>

#include "builder_base.hpp"
#include "manager_base.hpp"
#include "object_model.hpp"
#include "loader_source_base.hpp"

class BaseModelLoader
{
public:
    virtual ~BaseModelLoader() = default;
    virtual std::shared_ptr<Model> LoadModel(std::string model_name, std::string source_name) = 0;

protected:
    std::shared_ptr<BaseSourceLoader> loader_;
};

#endif // LOADER_BASE_HPP
