#include <iostream>

struct Container {
  std::string value{};

  // Here, the & qualifier is used to ensure
  // this function can only be used with the object
  // is an lvalue, which implies the returned reference
  // wont just be dangling in some cases
  const std::string &getValue() const & { return value; }

  // The && is used when we qualify against an rvalue,
  // so we instead copy instead of retuning a reference
  // to prevent dangling references
  const std::string getValue() const && { return value; }

  // Notice how these are overloaded functions,
  // ref qualifiers can be used in overloading just like this!
};
