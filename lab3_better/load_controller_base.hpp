#ifndef LOADER_BASE_HPP
#define LOADER_BASE_HPP

#include <memory>

#include "builder_model_base.hpp"
#include "manager_base.hpp"
#include "object_model.hpp"
#include "source_loader_base.hpp"

class BaseLoadController
{
public:
    virtual ~BaseLoadController() = default;
    virtual std::shared_ptr<SceneObject> load(std::string name, std::string source_name) = 0;
    virtual void SetSourceLoader(std::shared_ptr<BaseSourceLoader> loader) = 0;

protected:
    std::shared_ptr<BaseSourceLoader> source_loader_;
};

#endif // LOADER_BASE_HPP
