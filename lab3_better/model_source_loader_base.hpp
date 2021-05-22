#ifndef LOADER_SOURCE_BASE_HPP
#define LOADER_SOURCE_BASE_HPP

#include "vector.hpp"
#include "link.hpp"
#include "point.hpp"

class BaseModelSourceLoader
{
public:
    BaseModelSourceLoader() = default;
    ~BaseModelSourceLoader() noexcept = default;

    virtual void open(std::string source_name) = 0;
    virtual void close() = 0;

    virtual bool IsOpen() const = 0;

    virtual Vector<Point<double>> ReadPoints() = 0;
    virtual Vector<Link> ReadLinks() = 0;
    virtual Point<double> ReadCentre() = 0;
};

#endif // LOADER_SOURCE_BASE_HPP
