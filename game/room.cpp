#include "room.h"
#include "player.h"
#include <string>
#include <string_view>

Room::Room(std::string name, std::string desc) : m_name{name}, m_desc{desc} {}
std::string_view Room::getName() const { return m_name; }
std::string_view Room::getDesc() const { return m_desc; }

MainRoom::MainRoom(std::string name, std::string desc) : Room(name, desc) {}

void MainRoom::actOnPlayer(Player &player) {
  player.setCoins(player.getCoins() + 10);
}
