#ifndef DIRECTOR_MODEL_HPP
#define DIRECTOR_MODEL_HPP

#include <memory>

#include "builder_base.hpp"
#include "loader_source_base.hpp"
#include "object_model.hpp"

class ModelDirector
{
public:
    std::shared_ptr<Model> Build(const Vector<Point<double>> &points, const Vector<Link> &links);
    void SetBuilder(std::shared_ptr<BaseModelBuilder> builder);

private:
    std::shared_ptr<BaseModelBuilder> builder_;
};

#endif // DIRECTOR_MODEL_HPP
