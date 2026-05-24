#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <utility>

// A container parent class
// with a size and a size getter
class Container {
public:
  std::size_t m_size;

  std::size_t size() { return m_size; }

  Container(std::size_t size) : m_size{size} {}
};

// An array class which publically inherits container
template <typename T> class Array : public Container {
public:
  std::unique_ptr<T[]> m_data;
  explicit Array(std::size_t size)
      : Container{size}, m_data{std::make_unique<T[]>(size)} {}

  Array(std::initializer_list<T> list) : Array(list.size()) {

    std::copy(list.begin(), list.end(), m_data.get());
  }

  using Index = std::ptrdiff_t;

  const T &operator[](Index index) const { return m_data[index]; }

  T &operator[](Index index) {
    return const_cast<T &>(std::as_const(*this)[index]);
  }
};

int main(int argc, char **argv) {

  Array<int> arr(10);

  arr[2] = 3;

  auto n = arr.size();

  for (auto i{0}; i < n; ++i) {
    std::cout << arr[i] << '\n';
  }

  return 0;
}
