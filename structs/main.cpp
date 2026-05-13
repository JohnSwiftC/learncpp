#include <iostream>

// Slightly different than C, this is preffered
// a normal C struct does not need the list
// init, because in C you would typically write { 0 }
//
// here, this ensures the fields are set to defaults
// in the case of a SomeStrust s {};

struct SomeStruct {
  int value{};
  std::string name{};
};

int main() {

  SomeStruct s{12, "Bill"};

  std::cout << s.name << "\n";

  // in c++ 20 and onwards, we get rust like
  // named initializers

  SomeStruct nicer{.value = 10, .name = "Rick"};

  std::cout << nicer.name << '\n';

  // direct init with another struct

  SomeStruct direct(nicer);

  // copy is normal
  // not preffered

  SomeStruct copy = s;

  return 0;
}
