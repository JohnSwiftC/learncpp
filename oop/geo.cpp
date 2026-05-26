#include "geo.h"

#include <ostream>

Point3D::Point3D(double x, double y, double z) : m_x{x}, m_y{y}, m_z{z} {}

std::ostream &operator<<(std::ostream &out, const Point3D &in) {
  out << "(" << in.m_x << ", " << in.m_y << ", " << in.m_z << ")";

  return out;
}
