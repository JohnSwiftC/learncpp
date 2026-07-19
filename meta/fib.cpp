#include <iostream>
#include <type_traits>

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

// in the real world, these would use
// the standard library, and these are
// used to allow templates to make decisions

template <typename T> struct is_cool : std::false_type {};

struct Jeff;
struct John;
struct Bill;

template <> struct is_cool<John> : std::true_type {};
template <> struct is_cool<Bill> : std::true_type {};

// then use these in for example a templated function
// here you might want to check for a specific
// trait which may require things are done differently
// depending in the type
//
// also note the if constexpr. used here because
// is cool is just a template trait which will be known
// always at compile time

template <typename T> bool checker() {
  if constexpr (is_cool<T>::value) {
    return 1;
  } else {
    return 0;
  }
}

// this is some bs lol. since c++20, concepts are a thing
// they are very loosely like trait bounds in rust. lets say
// we want to write a template that only accepts types with some
// specific capability, like being cool.

template <typename T>
concept IsCool = is_cool<T>::value;

template <IsCool T> void hmm() {}

int main() {

  std::cout << Fib<10>::value << '\n';

  std::cout << factorial(10) << '\n';

  std::cout << is_pointer<int>::value << '\n';
  std::cout << is_pointer<char *>::value << "\n\n";

  // false, true, true

  std::cout << checker<Jeff>() << '\n';
  std::cout << checker<John>() << '\n';
  std::cout << checker<Bill>() << '\n';

  // below will not compile,
  // because int is not cool.
  // the nice part is the error message
  // is very clear and readable.
  // hmm<int>();

  // compiles just fine
  hmm<John>();

  return 0;
}
