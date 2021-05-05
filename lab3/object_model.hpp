#ifndef OBJECT_MODEL_HPP
#define OBJECT_MODEL_HPP

#include "link.hpp"
#include "point.hpp"
#include "carcass.hpp"
#include "object_visible.hpp"
#include "matrix.hpp"
#include "vector.hpp"
#include "visitor.hpp"

class Model : public VisibleObject
{
public:
    Model() = default;
    explicit Model(std::string name);
    Model(const Model &other);
    Model(Model &&other) noexcept;
    Model &operator=(const Model &other);
    Model &operator=(Model &&other) noexcept;
    ~Model() = default;

    void Transform(const std::shared_ptr<Matrix<double>> mtr) override;
    void Accept(std::shared_ptr<Visitor> visitor) override;

    std::shared_ptr<Carcass> GetCarcass();
    void Add(const Vector<Point<double>> &points);
    void Add(const Vector<Link> &links);

private:
    std::shared_ptr<Carcass> carcass_;
};

#endif // OBJECT_MODEL_HPP
