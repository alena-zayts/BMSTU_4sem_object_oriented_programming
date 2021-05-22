#include "builder_model.hpp"

void ModelBuilder::BuildPoints(const Vector<Point<double>> &points)
{
    model->carcass_->GetPoints() = points;
}

void ModelBuilder::reset(std::string name)
{
    model.reset();
    model = std::shared_ptr<Model>(std::make_shared<Model>(name));
}

void ModelBuilder::BuildLinks(const Vector<Link> &links)
{
    model->carcass_->GetLinks() = links;
}

void ModelBuilder::BuildCentre(const Point<double> centre)
{
    model->carcass_->GetCentre() = centre;
}

std::shared_ptr<Model> ModelBuilder::GetModel()
{
    return model;
}
