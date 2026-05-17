#ifndef BADVEC
#define BADVEC

#include <cstddef>
#include <optional>
template <typename T> struct badvec {

  using Index = std::ptrdiff_t;

  std::size_t cap;
  Index ptr;
  T *data;

  explicit badvec(std::size_t size) : cap{size}, ptr{0}, data{new T[size]} {}

  badvec(const badvec<T> &other)
      : cap{other.cap}, ptr{other.ptr}, data{new T[other.cap]} {
    for (std::size_t i{0}; i < other.cap; ++i) {
      data[i] = other.data[i];
    }
  }

  ~badvec() { delete[] data; }

  T &operator[](Index index) { return data[index]; }

  const T &operator[](Index index) const { return data[index]; }

  void push(T value) {
    if (static_cast<std::size_t>(ptr) == cap) {
      T *new_data = new T[cap + 1];

      for (std::size_t i{0}; i < cap; ++i) {
        new_data[i] = data[i];
      }

      delete[] data;
      data = new_data;
      cap++;

      data[ptr] = value;
      ptr++;

      return;
    }

    data[ptr] = value;
    ++ptr;

    return;
  }

  std::optional<T> pop() {
    if (ptr == 0) {
      return std::nullopt;
    }

    --ptr;

    return data[ptr];
  }
};

#endif
