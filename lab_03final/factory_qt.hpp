#ifndef FACTORY_QT_HPP
#define FACTORY_QT_HPP

#include "factory_abstract.hpp"
#include "drawer_qt.hpp"

class QtFactory : public AbstractFactory
{
public:
    std::shared_ptr<BaseDrawer> CreateUi() const override;
};

#endif // FACTORY_QT_HPP
