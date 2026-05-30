#include <iostream>

// Exceptions dont have a specific type in C++.
// you can throw and catch pretty much any type

void func_three();

int main(int argc, char *argv[]) {

  try {
    // throw an int exception

    throw -1;
  } catch (int e) {
    std::cout << e << '\n';
  }

  func_three();

  return 0;
}

// Like every other language that has exceptions, they unwind the stack
// and propogate to the closest handler within the call stack

void func_one() { throw "Bahhhh"; }

void func_two() {
  try {
    func_one();
  } catch (int) {
    // This handler does not fire, because func_one throws a const char *
    std::cout << "Int handler fired" << '\n';
  }
}

void func_three() {
  try {
    func_two();
  } catch (const char *e) {
    std::cout << e << '\n';
  }
}
