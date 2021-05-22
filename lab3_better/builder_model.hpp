#ifndef BUILDER_HPP
#define BUILDER_HPP

#include <memory>

#include "builder_model_base.hpp"
#include "model_source_loader_base.hpp"
#include "object_model.hpp"

class ModelBuilder : public BaseModelBuilder
{
public:
    ModelBuilder() = default;
    ~ModelBuilder() = default;

    void BuildPoints(const Vector<Point<double>> &points) override;
    void BuildLinks(const Vector<Link> &links) override;
    void BuildCentre(const Point<double> centre) override;
    void reset(std::string name) override;
    std::shared_ptr<Model> GetModel() override;

private:
    std::shared_ptr<Model> model;
};


#endif // BUILDER_HPP
