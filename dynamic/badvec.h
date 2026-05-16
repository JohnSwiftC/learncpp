#ifndef BADVEC
#define BADVEC

#include <cstddef>
template <typename T> struct badvec {

  using Index = std::ptrdiff_t;

  T *data;
  Index ptr;
  std::size_t cap;

  explicit badvec(std::size_t size) : cap{size}, ptr{0}, data{new T[size]} {}

  T &operator[](Index index) { return data[index]; }

  const T &operator[](Index index) const { return data[index]; }

  void push(T value) {
    if (static_cast<std::size_t>(ptr) == cap) {
      return;
    }

    data[ptr] = value;
    ++ptr;

    return;
  }

  T pop() {
    if (ptr == 0) {
      return data[0];
    }

    --ptr;

    return data[ptr];
  }
};

#endif
