#include "money.h"

Money operator+(const Money &a, const Money &b) {
  int dollars = a.m_dollars + b.m_dollars;
  int new_dollars = (a.m_cents + b.m_cents) / 100;
  int cents = (a.m_cents + b.m_cents) % 100;

  return Money{dollars + new_dollars, cents};
}
