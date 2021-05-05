#include "factory_qt.hpp"

std::shared_ptr<BaseDrawer> QtFactory::CreateUi() const
{
    return std::make_shared<QtDrawer>();
}
