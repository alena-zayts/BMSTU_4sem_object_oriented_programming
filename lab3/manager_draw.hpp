#ifndef MANAGER_DRAW_HPP
#define MANAGER_DRAW_HPP

#include "visitor.hpp"
#include "manager_base.hpp"
#include "matrix.hpp"
#include "drawer_base.hpp"
#include "scene.hpp"

class DrawManager : public BaseManager, public Visitor
{
public:
    void SetDrawer(std::shared_ptr<BaseDrawer> drawer);
    void SetCamera(std::shared_ptr<Camera> camera);
    void Visit(Model &model);
    void Visit(Camera &camera);
    void Visit(CompositeObject &comp);

private:
    std::shared_ptr<BaseDrawer> drawer_;
    std::shared_ptr<Camera> camera_;
    void ProjectPoint(Point<double> &point);
};

#endif // MANAGER_DRAW_HPP
