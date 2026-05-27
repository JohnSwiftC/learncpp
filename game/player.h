#ifndef PLAYER_H
#define PLAYER_H

#include <iosfwd>
#include <memory>

class Room;

class Player {
private:
  int m_coins;
  Room *m_curr_room;

public:
  Player(Room *room);
  int getCoins() const;
  void setCoins(int coins);

  friend std::ostream &operator<<(std::ostream &out, const Player &in);
};

#endif
