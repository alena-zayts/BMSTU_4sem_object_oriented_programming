#ifndef LOADER_SOURCE_FILE_HPP
#define LOADER_SOURCE_FILE_HPP

#include <fstream>

#include "vector.hpp"
#include "link.hpp"
#include "model_source_loader_base.hpp"

class FileModelSourceLoader : public BaseModelSourceLoader
{
public:
    FileModelSourceLoader() = default;
    ~FileModelSourceLoader();

    void open(std::string source_name) override;
    void close() override;

    bool IsOpen() const override;
    Vector<Point<double>> ReadPoints() override;
    Vector<Link> ReadLinks() override;
    Point<double> ReadCentre() override;

private:
    std::ifstream file_;
};

#endif // LOADER_SOURCE_FILE_HPP
