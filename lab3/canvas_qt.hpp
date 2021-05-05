#ifndef CANVAS_QT_HPP
#define CANVAS_QT_HPP

#include <QGraphicsScene>
#include <memory>

#include "canvas_base.hpp"

class QtCanvas : public BaseCanvas
{
public:
    explicit QtCanvas(std::shared_ptr<QGraphicsScene> canvas_);
    void DrawLine(const Point<double> &p1, const Point<double> &p2) override;

private:
    std::shared_ptr<QGraphicsScene> graphics_scene_;
};

#endif // CANVAS_QT_HPP
