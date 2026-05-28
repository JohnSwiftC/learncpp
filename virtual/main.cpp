#include <iostream>

// This is ripped straight from learncpp,
// virtual base classes ensure that if a derived class inherits
// a class using one (or multiple, they construct only one underlying object)

class Number {};

class Integer : public virtual Number {};

class Imaginary : public virtual Number {};

// Complex inherits both integer and imaginary,
// which both inherit number.
// normally, this would result in two Numbers being constructed,
// however,
// because imaginary and integer implement number as a virtual base class,
// they will share only a single instance
class Complex : public Integer, public Imaginary {};
