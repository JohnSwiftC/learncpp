#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room {
private:
  std::string m_name;

public:
  Room(std::string name);
  std::string_view getName();
};

#endif
