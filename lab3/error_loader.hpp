#ifndef ERROR_LOADER_HPP
#define ERROR_LOADER_HPP

#include "error_base.hpp"

class OpenStreamError : public BaseError
{
public:
    OpenStreamError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Openinng Stream Error") : BaseError(filename, classname, line, time, info) {}
};

class ReadStreamError : public BaseError
{
public:
    ReadStreamError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Reading Stream Error") : BaseError(filename, classname, line, time, info) {}
};

class FileFormatError : public BaseError
{
public:
    FileFormatError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "File Format Error") : BaseError(filename, classname, line, time, info) {}
};


#endif // ERROR_LOADER_HPP
