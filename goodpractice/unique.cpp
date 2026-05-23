#include <iostream>
#include <memory>
#include <ostream>

class Vector3D {
private:
  double m_x;
  double m_y;
  double m_z;

public:
  Vector3D(double x, double y, double z) : m_x{x}, m_y{y}, m_z{z} {}

  friend std::ostream &operator<<(std::ostream &out, const Vector3D &in) {
    out << "(" << in.m_x << ", " << in.m_y << ", " << in.m_z << ")";

    return out;
  }
};

class Triangle {
  using PointPtr = std::unique_ptr<Vector3D>;

private:
  PointPtr m_first;
  PointPtr m_second;
  PointPtr m_third;

public:
  // You have to move in the initializer list because
  // the arguments are named values, and thus are lvalues
  Triangle(PointPtr first, PointPtr second, PointPtr third)
      : m_first{std::move(first)}, m_second{std::move(second)},
        m_third{std::move(third)} {}
};

int main() {

  // new is not good practice.
  // just use make_unique
  // instead of manually allocating memory,
  // role of zero :)))

  std::unique_ptr<Vector3D> point1{std::make_unique<Vector3D>(1.0, 2.0, 3.0)};
  std::unique_ptr<Vector3D> point2{std::make_unique<Vector3D>(2.0, 10.0, 12.0)};
  std::unique_ptr<Vector3D> point3{std::make_unique<Vector3D>(3.0, 3.0, 1.0)};

  return 0;
}
