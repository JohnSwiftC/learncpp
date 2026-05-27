#include "player.h"
#include "room.h"
#include <iostream>

int main() {
  MainRoom main_room{"Main Room", "You find yourself in the main room..."};

  Player player{&main_room};

  std::cout << player << '\n';
  std::cout << main_room.getName() << '\n';

  main_room.actOnPlayer(player);

  std::cout << player << '\n';

  return 0;
}
