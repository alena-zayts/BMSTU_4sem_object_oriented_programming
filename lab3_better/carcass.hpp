#ifndef CARCASS_HPP
#define CARCASS_HPP

#include "matrix.hpp"
#include "points_pair.hpp"
#include "vector.hpp"
#include "link.hpp"
#include "point.hpp"

// совокупность точек и связей
class Carcass
{
public:
    Carcass() = default;
    Carcass(const Vector<Point<double>> &points, const Vector<Link> &links);
    ~Carcass() = default;

    Vector<Point<double>> &GetPoints();
    Vector<Link> &GetLinks();
    Vector<Pair<Point<double>, Point<double>>> GetEdges();
    void Transform(const std::shared_ptr<Matrix<double>> mtr);

private:
    Vector<Point<double>> points_;
    Vector<Link> links_;
};

#endif // CARCASS_HPP
