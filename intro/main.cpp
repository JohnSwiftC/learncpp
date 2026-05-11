#include <iostream>

int postname(int);

int main() {
  // cpp already presents as the most annoying language
  // of all time

  int a{2};

  int b{postname(a)};

  std::cout << "Num: " << b << '\n';

  // Book actually getting to something
  // interesting :3
  double c{static_cast<double>(5)};
  std::cout << c << '\n';

  constexpr int this_is_compile_time{4};

  std::cout
      << "Optimized (well so are the other ones, but in this case, the value \
  must be evaled as a constexpr): "
      << this_is_compile_time << '\n';

  return 0;
}

int postname(int bull) { return bull * 2; }
