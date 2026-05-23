#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <ostream>
#include <utility>

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

class MyArray {
private:
  std::size_t m_size;
  std::unique_ptr<int[]> m_data;

public:
  explicit MyArray(std::size_t size)
      : m_size{size}, m_data{std::make_unique<int[]>(size)} {}

  // Takes an initializer_list, delegates to the first constructor based on
  // size, and then copies the elements of the initializer over
  MyArray(std::initializer_list<int> list) : MyArray(list.size()) {
    std::copy(list.begin(), list.end(), m_data.get());
  }

  // Contains a unique_ptr, so
  // its good to explicity delete the
  // copy constructors
  MyArray &operator=(const MyArray &) = delete;
  MyArray(const MyArray &) = delete;

  const int &operator[](std::ptrdiff_t index) const { return m_data[index]; }
  int &operator[](std::ptrdiff_t index) {
    return const_cast<int &>(std::as_const(*this)[index]);
  }

  std::size_t size() const { return m_size; }
};

int main() {

  // new is not good practice.
  // just use make_unique
  // instead of manually allocating memory,
  // role of zero :)))

  std::unique_ptr<Vector3D> point1{std::make_unique<Vector3D>(1.0, 2.0, 3.0)};
  std::unique_ptr<Vector3D> point2{std::make_unique<Vector3D>(2.0, 10.0, 12.0)};
  std::unique_ptr<Vector3D> point3{std::make_unique<Vector3D>(3.0, 3.0, 1.0)};

  if (point1) {
    std::cout << *point1 << '\n';
  }

  // std::move must also be used in the constructor,
  // for the same reasons as above
  Triangle tri{std::move(point1), std::move(point2), std::move(point3)};

  // the whole point of unique_ptr is that it's delete constructor
  // handles deletion for you, so when tri is deleted, the underlying
  // memory for the allocated points will also be deleted

  MyArray arr{1, 2, 3, 4, 5};

  std::size_t n = arr.size();

  for (std::size_t i{0}; i < n; ++i) {
    std::cout << arr[i] << '\n';
  }

  return 0;
}
