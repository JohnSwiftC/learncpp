#include <bitset>
#include <iostream>

int main() {
  std::bitset<12> set{0};

  std::cout << set << '\n';

  // Actually a fan of these
  // writing something like this is rust to be
  // efficient is nontrivial and im not sure
  // there is one in the standard library

  for (int i = 0; i < 12; i += 2) {
    set.flip(i);
  }

  std::cout << set << '\n';

  return 0;
}
