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

// in the real world, this is just constexpr'ed

constexpr int factorial(int n) {
  if (n == 0) {
    return 1;
  }

  return n * factorial(n - 1);
}

// this is where things
// get more interesting,
// templates are used to make type traits,
// which can be used to mess with or examine types
// at compile time.
//
// This will tell you at compile time if a
// type is a pointer

template <typename T> struct is_pointer {
  static constexpr bool value = false;
};

template <typename T> struct is_pointer<T *> {
  static constexpr bool value = true;
};

int main() {

  std::cout << Fib<10>::value << '\n';

  std::cout << factorial(10) << '\n';

  std::cout << is_pointer<int>::value << '\n';
  std::cout << is_pointer<char *>::value << '\n';

  return 0;
}
