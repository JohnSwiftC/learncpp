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

  SomeStruct(int v) : value{v}, name{"unnamed"} {}
  SomeStruct(int v, std::string s) : value{v}, name{s} {}
  // SomeStruct(int v = 0, std::string s = "unnamed") : value{v}, name{s} {}

  SomeStruct() = default;
};

int main() {

  SomeStruct s{12, "Bill"};

  std::cout << s.name << "\n";

  // direct init with another struct

  SomeStruct direct(s);

  // copy is normal
  // not preffered

  SomeStruct copy = s;

  // using the default constructor

  SomeStruct def{};

  std::cout << def.value << def.name << '\n';

  return 0;
}
