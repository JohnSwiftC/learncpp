#include <iostream>
#include <string_view>

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

  // Important to be using string_view here
  // to avoid the copy when the constructor is called
  // #couldbesolvedviacopyorclonetrait
  SomeStruct(int v, std::string_view s) : value{v}, name{s} {}
  // SomeStruct(int v = 0, std::string s = "unnamed") : value{v}, name{s} {}

  // Delegating

  SomeStruct(std::string_view s) : SomeStruct{67, s} {}

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

  // Using delegated

  SomeStruct dele{"Hello, World!"};

  std::cout << dele.value << '\n';

  return 0;
}
