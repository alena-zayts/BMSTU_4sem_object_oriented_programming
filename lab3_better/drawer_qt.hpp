#ifndef DRAWER_QT_HPP
#define DRAWER_QT_HPP

#include <QGraphicsScene>
#include <memory>

#include "drawer_base.hpp"
#include "point.hpp"

class QtDrawer : public BaseDrawer
{
public:
    QtDrawer() = default;

    void drawLine(const Point<double> &p1, const Point<double> &p2) override;
    void setCanvas(std::shared_ptr<BaseCanvas> canvas_) override;
};


#endif // DRAWER_QT_HPP
