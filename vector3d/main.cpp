#include <iostream>
#include <ostream>

struct Vector3D {
  double m_x{};
  double m_y{};
  double m_z{};

  Vector3D() = default;

  Vector3D(double x, double y, double z) : m_x{x}, m_y{y}, m_z{z} {}

  // Copy constructor
  // Called whenever the struct is copied
  // for example, in function calls by value
  Vector3D(const Vector3D &vector3d)
      : m_x{vector3d.m_x}, m_y{vector3d.m_y}, m_z{vector3d.m_z} {}

  // We can also delete the copy constructor to prevent
  // copy

  // Vector3D(const Vector3D&) = delete;

  constexpr void add(const Vector3D &other) {
    m_x += other.m_x;
    m_y += other.m_y;
    m_z += other.m_z;
  }

  constexpr void sub(const Vector3D &other) {
    m_x -= other.m_x;
    m_y -= other.m_y;
    m_z -= other.m_z;
  }

  std::string to_string() const {
    return "(" + std::to_string(m_x) + ", " + std::to_string(m_y) + ", " +
           std::to_string(m_z) + ")";
  }
};

std::ostream &operator<<(std::ostream &out, const Vector3D &in) {
  out << in.to_string();
  return out;
}

int main() {

  Vector3D vec{};

  vec.add({3, 2, 1});
  vec.sub({0.5, 0.5, 0.5});

  std::cout << vec << '\n';

  return 0;
}
