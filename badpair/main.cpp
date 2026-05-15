#include <iostream>

template <typename T> struct Pair {
  T m_first{};
  T m_second{};

  Pair(const T &first, const T &second) : m_first{first}, m_second{second} {}

  void add(const Pair<T> &pair);
};

// This is a deduction guide,
// a pair called with this constructor should
// have type T
template <typename T> Pair(T, T) -> Pair<T>;

// Adding outside of the class def
// requires the use of the generic type
// also, note how i only have to do it once,
// as other pairs in the function are assumed
// to then be of type T!
template <typename T> void Pair<T>::add(const Pair &other) {
  m_first += other.m_first;
  m_second += other.m_second;
}

int main() {
  Pair<int> int_pair = Pair{1, 3};

  return 0;
}
