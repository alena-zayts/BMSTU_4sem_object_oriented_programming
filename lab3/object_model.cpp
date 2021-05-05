#include "object_model.hpp"

Model::Model(const Model &other) : VisibleObject(), carcass_(other.carcass_) {}

Model::Model(Model &&other) noexcept : carcass_(other.carcass_) {}

Model::Model(std::string name) : carcass_(std::make_shared<Carcass>())
{
    this->name_ = name;
}

Model &Model::operator=(const Model &other)
{
    if (this != &other)
    {
        carcass_ = other.carcass_;
    }

    return *this;
}

Model &Model::operator=(Model &&other) noexcept
{
    if (this != &other)
    {
        carcass_ = other.carcass_;
    }

    return *this;
}

std::shared_ptr<Carcass> Model::GetCarcass()
{
    return carcass_;
}

void Model::Transform(const std::shared_ptr<Matrix<double>> mtr)
{
    carcass_->Transform(mtr);
}

void Model::Accept(std::shared_ptr<Visitor> visitor)
{
    visitor->Visit(*this);
}

void Model::Add(const Vector<Point<double>> &points)
{
    carcass_->AddPoints(points);
}

void Model::Add(const Vector<Link> &links)
{
    carcass_->AddLinks(links);
}
