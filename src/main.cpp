#include "../include/game.h"

int main(int argc, char const **argv) {
  Game game = Game::getInstance();
  game.run();
  return 0;
}