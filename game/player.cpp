#include "player.h"
#include "room.h"
#include <ostream>

Player::Player(Room *room) : m_coins{0}, m_curr_room{room} {}
int Player::getCoins() const { return m_coins; }
void Player::setCoins(int coins) { m_coins = coins; }

std::ostream &operator<<(std::ostream &out, const Player &in) {
  out << "Coins: " << in.m_coins << '\n';

  return out;
}
