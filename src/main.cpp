#include "../include/game.h"

void play(Game* game, bool autoPlay, int playerNumber){
  game->run(autoPlay, playerNumber);
}


int main (int argc, char const **argv) {
  bool exit = false;
  srand(time(NULL));

  while(!exit){
    int number;
    std::cout << "0 - para jogar o jogo" << std::endl;
    std::cout << "1 - para sair" << std::endl;
    std::cin >> number;
    if(number == 0){
      Game game = Game::getInstance();
      std::thread first(play, &game, false, 1);
      std::thread second(play, &game, true, 2);
      first.join();
      second.join();

      return 0;
    }
    else if (number == 1){
      exit = true;
      std::cout << "Good Bye!" << std::endl; 
    } else{
      std::cout << std::endl << "Digite um número de 0 a 2" << std::endl;
    }
  }

  return 0;
}
