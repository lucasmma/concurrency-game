#include "../include/game.h"

Game* Game::instance;

Game::Game(){
  state = new State();
  primaryPlayer = true;
}

Game& Game::getInstance(){
  if (instance != nullptr){
      // std::cout << "Intancia ja existente" << std::endl;
      return *instance;
  }
  else{
      Game *game = new Game();
      instance = game;
      return *game;
  }
}

Game::~Game(){
}

void Game::run(){
  state->start();
  state->render();
  while (!state->isGameFinished()) {
    std::cout << std::endl <<"Vez do jogador "<< (primaryPlayer ? 1: 2) << std::endl;
    std::vector<int> inputHandled = handleInput();
    while(!state->enqueuePlay(inputHandled, primaryPlayer ? 1 : 2)){
      inputHandled = handleInput(true);
    }
    state->update();
    state->render();
    primaryPlayer = !primaryPlayer;
    // return;
  }
}

std::vector<int> Game::handleInput(bool invalidPlay){
  if(invalidPlay) {
    std::cout << std::endl << "Espaço está indisponível, escolha outro espaço" << std::endl;
  } else{
    std::cout << "Insira dois numeros de 0 a 7" << std::endl;
  }
  std::string input;
  std::cin >> input;

  std::vector<int> axisInput(2, 0);

  if (input.size() != 2){
    std::cout << "Deve ser digitado 2 casas decimais, uma para o eixo x e a outra para o eixo y" << std::endl;
    return handleInput();
  } else if (!isdigit(input[0]) || !isdigit(input[1])){
    std::cout << "Deve ser digitado apenas números" << std::endl;
    return handleInput();
  } else{
    axisInput[0] = (int)(input[0] - '0');
    axisInput[1] = (int)(input[1] - '0');
    if (axisInput[0] >= Board::width || axisInput[1] >= Board::height){
      std::cout << "Deve ser digitado apenas números de 0 a 7" << std::endl;
      return handleInput();
    }
  }

  return axisInput;
}