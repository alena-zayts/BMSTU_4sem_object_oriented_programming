#ifndef DIRECTOR_MODEL_HPP
#define DIRECTOR_MODEL_HPP

#include <memory>

#include "builder_model_base.hpp"
#include "model_source_loader_base.hpp"
#include "object_model.hpp"

class ModelDirector
{
public:
    std::shared_ptr<Model> Build(const Vector<Point<double>> &points, const Vector<Link> &links, const Point<double> centre);
    void SetBuilder(std::shared_ptr<BaseModelBuilder> builder);

private:
    std::shared_ptr<BaseModelBuilder> builder_;
};

#endif // DIRECTOR_MODEL_HPP
