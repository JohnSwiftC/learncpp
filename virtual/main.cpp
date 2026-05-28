#include <iostream>

// This is ripped straight from learncpp,
// virtual base classes ensure that if a derived class inherits
// a class using one (or multiple, they construct only one underlying object)

class Number {
public:
  Number() { std::cout << "Constructing Number" << '\n'; }
};

class Integer : public virtual Number {
public:
  Integer() { std::cout << "Constructing Integer" << '\n'; }
};

class Imaginary : public virtual Number {
public:
  Imaginary() { std::cout << "Constructing Imaginary" << '\n'; }
};

// Complex inherits both integer and imaginary,
// which both inherit number.
// normally, this would result in two Numbers being constructed,
// however,
// because imaginary and integer implement number as a virtual base class,
// they will share only a single instance
class Complex : public Integer, public Imaginary {
public:
  Complex() { std::cout << "Constructing Complex" << '\n'; }
};

int main() {
  Complex comp;

  return 0;
}
