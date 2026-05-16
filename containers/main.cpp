#include <cstddef>
#include <iostream>
#include <vector>

// Vectors can be returned by value
// as they have move-semantics, this
// does not copy and just gives the underlying data
// a new owner
template <typename T> std::vector<T> init(std::size_t size, T init) {
  std::vector<T> ret(size);

  for (std::size_t i = 0; i < size; ++i) {
    ret[i] = init;
  }

  return ret;
}

template <typename T> void display_vector(const std::vector<T> &vec) {
  for (std::size_t i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << "\n";
  }
}

template <typename T> class VectorView {
private:
  T &internal;

public:
  // Creating a class member type
  using Index = std::ptrdiff_t;

  // overload [] operator
  // this also uses the size_type, which is normally
  // in a container class, to cast our index type into
  // what it expects
  constexpr T &operator[](Index index) {
    return internal[static_cast<typename T::size_type>(index)];
  }

  // For when the view is constant
  constexpr const T &operator[](Index index) const {
    return internal[static_cast<typename T::size_type>(index)];
  }
};

int main() {
  // Some simple
  // container things

  // List initialized
  std::vector<int> my_nums{0, 1, 2, 3};

  // Uses the explicit constructor
  // to make a vector with capacity 10
  // and zero-inits the elements
  std::vector<int> zero(10);

  std::vector<int> ones = init(20, 1);

  display_vector(ones);

  return 0;
}
