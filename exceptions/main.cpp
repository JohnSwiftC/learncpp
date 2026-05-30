#include <iostream>
#include <ostream>

// Exceptions dont have a specific type in C++.
// you can throw and catch pretty much any type

void func_three();

// Enums for error types

enum class MyError {
  Something,
  Else,
  Foo,
  Bar,
};

std::ostream &operator<<(std::ostream &out, const MyError &in) {
  switch (in) {
  case MyError::Bar:
    out << "Bar";
    break;
  case MyError::Foo:
    out << "Foo";
    break;
  case MyError::Something:
    out << "Something";
    break;
  case MyError::Else:
    out << "Else";
  }

  return out;
}

void throws_my_error();

int main(int argc, char *argv[]) {

  try {
    // throw an int exception

    throw -1;
  } catch (int e) {
    std::cout << e << '\n';
  }

  func_three();

  try {
    throws_my_error();
  } catch (MyError e) {
    std::cout << e << '\n';
  }

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

void throws_my_error() { throw MyError::Foo; }
