#include "../include/game.h"

int main(int argc, char const **argv) {
  bool exit = false;
  if(argc < 2){
    std::cout << "Digite um número de jogador ao executar o programa" << std::endl;
    return 0;
  } else if(argc > 2){
    std::cout << "Digite apenas número de jogador ao executar o programa" << std::endl;
    return 0;
  } else {
    int playerNumber = (int)(*argv[1] - '0');
    // std::cout << playerNumber << std::endl;
    if(playerNumber != 1 && playerNumber != 2) {
      std::cout << "Os números de jogadores diponíveis são apenas o 1 e o 2" << std::endl;
      return 0;
    }
  }
  while(!exit){
    int number;
    std::cout << "0 - para jogar o jogo" << std::endl;
    std::cout << "1 - para limpar a cache" << std::endl;
    std::cout << "2 - para sair" << std::endl;
    std::cin >> number;
    if(number == 0){
      Game game = Game::getInstance();
      game.run((int)(*argv[1] - '0'));
      return 0;
    }
    else if(number == 1){
      Game game = Game::getInstance();
      game.run((int)(*argv[1] - '0'), true);
      std::cout <<  std::endl;
    }
    else if (number == 2){
      exit = true;
    } else{
      std::cout << std::endl << "Digite um número de 0 a 2" << std::endl;
    }
  }

  return 0;
}