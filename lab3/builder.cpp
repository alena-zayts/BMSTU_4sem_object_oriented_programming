#include "builder.hpp"

void ModelBuilder::BuildPoints(const Vector<Point<double>> &points)
{
    model->Add(points);
}

void ModelBuilder::reset(std::string name)
{
    model.reset();
    model = std::shared_ptr<Model>(std::make_shared<Model>(name));
}

void ModelBuilder::BuildLinks(const Vector<Link> &links)
{
    model->Add(links);
}

std::shared_ptr<Model> ModelBuilder::GetModel()
{
    return model;
}
