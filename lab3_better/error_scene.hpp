#ifndef ERROR_SCENE_HPP
#define ERROR_SCENE_HPP

#include "error_base.hpp"

class CameraError : public BaseError
{
public:
    CameraError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Camera is not set") : BaseError(filename, classname, line, time, info) {}
};

class ObjectError : public BaseError
{
public:
    ObjectError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Object is not found.") : BaseError(filename, classname, line, time, info) {}
};

#endif // ERROR_SCENE_HPP
