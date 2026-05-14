#include <iostream>
#include <ostream>

struct Vector3D {
  double m_x{};
  double m_y{};
  double m_z{};

  Vector3D() = default;

  // Explicit here means that this cannot be used
  // as a conversion constructor, must be explicitly used
  // as a constructor and nothing else
  explicit constexpr Vector3D(double x, double y, double z)
      : m_x{x}, m_y{y}, m_z{z} {}

  // Copy constructor
  // Called whenever the struct is copied
  // for example, in function calls by value
  //
  // Copy constructors should NOT have side effects.
  // Primarily due to copy ellision, because the compiler
  // is free to optimize away copies, so we cannot be sure
  // when the constructor will actually be called
  Vector3D(const Vector3D &vector3d)
      : m_x{vector3d.m_x}, m_y{vector3d.m_y}, m_z{vector3d.m_z} {}

  // We can also delete the copy constructor to prevent
  // copying

  // Vector3D(const Vector3D&) = delete;

  constexpr Vector3D &add(const Vector3D &other) {
    m_x += other.m_x;
    m_y += other.m_y;
    m_z += other.m_z;

    return *this;
  }

  constexpr Vector3D &sub(const Vector3D &other) {
    m_x -= other.m_x;
    m_y -= other.m_y;
    m_z -= other.m_z;

    return *this;
  }

  std::string to_string() const {

    // This is a pointer to the implicit object in the function call,
    // not required but useful

    return "(" + std::to_string(this->m_x) + ", " + std::to_string(m_y) + ", " +
           std::to_string(m_z) + ")";
  }
};

std::ostream &operator<<(std::ostream &out, const Vector3D &in) {
  out << in.to_string();
  return out;
}

int main() {

  Vector3D vec{};

  // Chaining, class functions return a ref to the object so methods can be
  // chained
  vec.add(Vector3D{3, 2, 1}).sub(Vector3D{0.5, 0.5, 0.5});

  std::cout << vec << '\n';

  return 0;
}
