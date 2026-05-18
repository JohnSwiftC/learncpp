#include <iostream>

int main(int argc, char *argv[]) {

  auto add{[](auto a, auto b) { return a + b; }};

  // Here we have an add function defined as a lambda with
  // two auto params. This behaves pretty much like a template.

  int ints{add(3, 5)};

  double doubles{add(1.5, 3.2)};

  // These are two different functions that are being
  // generated. A static would not be shared between the two
  // because one is (int, int) and the other is (double, double);

  // when lambdas capture, they copy. These copies are not
  // mutable by default, so the lambda must be marked to do so
  // the captured variable is static in the lambda, but keep in mind
  // it is still a copy

  int placeholder{10};

  auto decrement{[placeholder]() mutable {
    --placeholder;
    std::cout << placeholder << '\n';
  }};

  decrement(); // prints 8
  decrement(); // prints 7

  // This, however, is still 10.
  // good thing we can capture references
  std::cout << placeholder << '\n';

  // Notice also how when we capture by ref,
  // the lambda does not need to be marked as mutable
  auto increment{[&placeholder]() {
    ++placeholder;
    std::cout << placeholder << '\n';
  }};

  increment();
  increment();
  increment();

  std::cout << placeholder << '\n';

  // we can also use default captures

  // captures everything we reference in the function by reference,
  // can also use = to capture everything via copy
  auto double_lam{[&]() { ints *= 2; }};

  return 0;
}
