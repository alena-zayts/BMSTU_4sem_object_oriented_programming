#ifndef CANVAS_BASE_HPP
#define CANVAS_BASE_HPP

#include "point.hpp"

class BaseCanvas
{
public:
    virtual void DrawLine(const Point<double> &p1, const Point<double> &p2) = 0;
};

#endif // CANVAS_BASE_HPP
