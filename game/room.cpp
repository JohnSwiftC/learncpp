#include "room.h"
#include <string>

Room::Room(std::string name) : m_name{name} {}
std::string_view Room::getName() { return m_name; }
