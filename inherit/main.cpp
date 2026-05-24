#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <memory>

// A container parent class
// with a size and a size getter
class Container {
public:
  std::size_t m_size;

  std::size_t size() { return m_size; }

  Container(std::size_t size) : m_size{size} {}
};

// A vector class which publically inherits container
template <typename T> class Vector : public Container {
public:
  std::unique_ptr<T[]> m_data;
  Vector(std::size_t size)
      : Container{size}, m_data{std::make_unique<T[]>(size)} {}

  Vector(std::initializer_list<T> list)
      : Vector(list.size()), m_data{std::make_unique<T[]>(m_size)} {

    std::copy(list.begin(), list.end(), m_data.get());
  }
};
