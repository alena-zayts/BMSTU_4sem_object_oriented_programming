#ifndef DRAWER_BASE_HPP
#define DRAWER_BASE_HPP

#include "canvas_base.hpp"
#include "point.hpp"

class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = default;

    virtual void drawLine(const Point<double> &p1, const Point<double> &p2) = 0;
    virtual void setCanvas(std::shared_ptr<BaseCanvas> canvas) = 0;

    std::shared_ptr<BaseCanvas> canvas;
};


#endif // DRAWER_BASE_HPP
