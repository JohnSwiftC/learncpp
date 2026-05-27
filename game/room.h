#ifndef ROOM_H
#define ROOM_H

#include <string>

class Player;

class Room {
private:
  std::string m_name;
  std::string m_desc;

public:
  Room(std::string name, std::string desc);
  std::string_view getName() const;
  std::string_view getDesc() const;

  virtual void actOnPlayer(Player &player) = 0;
};

class MainRoom : public Room {
public:
  MainRoom(std::string name, std::string desc);

  void actOnPlayer(Player &player) override;
};

#endif
