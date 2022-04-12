#include "../include/Game.h"

Game* Game::instance;

Game::Game(){
  state = new State();
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
    handleInput();
    state->update();
    state->render();
    return;
  }
}

vector<int> Game::handleInput(){

  cout << endl << "Insira dois numeros de 0 a 7" << endl;
  string input;
  cin >> input;

  vector<int> axisInput(2, 0);

  if (input.size() != 2){
    cout << "Deve ser digitado 2 casas decimais, uma para o eixo x e a outra para o eixo y" << endl;
    return handleInput();
  } else if (!isdigit(input[0]) || !isdigit(input[1])){
    cout << "Deve ser digitado apenas números" << endl;
    return handleInput();
  } else{
    axisInput[0] = (int)(input[0] - '0');
    axisInput[1] = (int)(input[1] - '0');
  }
  
  return axisInput;
}