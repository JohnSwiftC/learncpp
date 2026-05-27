#ifndef PLAYER_H
#define PLAYER_H

#include "room.h"
#include <iosfwd>
#include <memory>

class Player {
private:
  int m_coins;
  Room *m_curr_room;

public:
  Player(Room *room);

  friend std::ostream &operator<<(std::ostream &out, const Player &in);
};

#endif
