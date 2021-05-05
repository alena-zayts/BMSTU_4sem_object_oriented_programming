#include "carcass.hpp"

Carcass::Carcass(const Vector<Point<double>> &points, const Vector<Link> &links)
{
    points_ = points;
    links_ = links;
}

void Carcass::AddPoints(const Vector<Point<double>> &points)
{
    points_ = points;
}

void Carcass::AddLinks(const Vector<Link> &links)
{
    links_ = links;
}

Vector<Link> &Carcass::GetLinks()
{
    return links_;
}

Vector<Point<double>> &Carcass::GetPoints()
{
    return points_;
}

Vector<Pair<Point<double>, Point<double>>> Carcass::GetEdges()
{
    Vector<Pair<Point<double>, Point<double>>> edges;

    for (int i = 0; i < links_.getLen(); i++)
    {
        Pair<Point<double>, Point<double>> tmp(points_[links_[i].GetBegin()], points_[links_[i].GetEnd()]);
        edges.push_back(tmp);
    }

    return edges;
}

void Carcass::Transform(const std::shared_ptr<Matrix<double>> mtr)
{
    for (int i = 0; i < points_.getLen(); i++)
    {
        points_[i].Transform(mtr);
    }
}

