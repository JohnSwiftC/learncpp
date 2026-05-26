#ifndef GEO_H
#define GEO_H

#include <iosfwd> // Forward decl, can reference needed
// items but the implementation is not here,
// improves build times and makes the includes a little more sane

class Point3D {
private:
  double m_x;
  double m_y;
  double m_z;

public:
  Point3D(double x, double y, double z);

  friend std::ostream &operator<<(std::ostream &out, const Point3D &in);
};

#endif
