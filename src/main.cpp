#include "../include/game.h"

int main(int argc, char const **argv) {
  Game game = Game::getInstance();
  game.run((int)(*argv[1] - '0'));
  return 0;
}