#include "money.h"
#include <iostream>

int main() {
  Money one{10, 50};
  Money two{1, 70};

  Money sum = one + two;

  std::cout << sum << '\n';

  return 0;
}
