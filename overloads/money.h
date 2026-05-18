#ifndef MONEY_H
#define MONEY_H

#include <ostream>
class Money {
private:
  int m_dollars;
  int m_cents;

public:
  explicit Money(int dollars, int cents) : m_dollars{dollars}, m_cents{cents} {}
  explicit Money(int dollars) : m_dollars{dollars}, m_cents{0} {}

  // Declare the operator as a friend function so it
  // can access the private member fields
  friend Money operator+(const Money &a, const Money &b);
  friend std::ostream &operator<<(const std::ostream &out, const Money &in) {}
};

#endif
