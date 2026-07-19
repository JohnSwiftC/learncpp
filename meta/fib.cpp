#include <iostream>

// my eyes have been opened

template <int N> struct Fib {
  static const int value = Fib<N - 1>::value + Fib<N - 2>::value;
};

template <> struct Fib<1> {
  static const int value = 1;
};

template <> struct Fib<2> {
  static const int value = 1;
};

int main() {

  std::cout << Fib<10>::value << '\n';

  return 0;
}
