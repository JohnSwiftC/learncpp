#include <iostream>
#include <string_view>

std::string_view rust_would_not_compile() {
  /*
   * As explained earlier, string_view is a view or a reference to a string
   * so obviously returning a ref to an owned variable which drops out of scope
   * is UB
   */

  std::string str{"Hello World"};

  return static_cast<std::string_view>(str);
}

int main() {
  std::cout << rust_would_not_compile() << '\n';

  // This is obviously UB because of bad ownership rules
  // if only they has a borrow checker to prevent this.
  // also the string_view returned now points to garbage

  return 0;
}
