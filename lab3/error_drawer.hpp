#ifndef ERROR_DRAWER_HPP
#define ERROR_DRAWER_HPP

#include "error_base.hpp"
#include "error_scene.hpp"

class DrawerError : public BaseError
{
public:
    DrawerError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Drawer wasn't set") : BaseError(filename, classname, line, time, info) {}
};


#endif // ERROR_DRAWER_HPP
