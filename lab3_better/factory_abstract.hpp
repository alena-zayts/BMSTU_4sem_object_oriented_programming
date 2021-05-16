#ifndef FACTORY_ABSTRACT_HPP
#define FACTORY_ABSTRACT_HPP

#include <memory>

#include "drawer_base.hpp"

class AbstractFactory
{
public:
    virtual std::shared_ptr<BaseDrawer> CreateUi() const = 0;
};

#endif // FACTORY_ABSTRACT_HPP
