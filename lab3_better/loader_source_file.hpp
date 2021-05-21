#ifndef LOADER_SOURCE_FILE_HPP
#define LOADER_SOURCE_FILE_HPP

#include <fstream>

#include "vector.hpp"
#include "link.hpp"
#include "loader_source_base.hpp"

class FileModelSource : public BaseModelSource
{
public:
    FileModelSource() = default;
    ~FileModelSource();

    void open(std::string source_name) override;
    void close() override;

    bool IsOpen() const override;
    Vector<Point<double>> ReadPoints() override;
    Vector<Link> ReadLinks() override;

private:
    std::ifstream file_;
};

#endif // LOADER_SOURCE_FILE_HPP
