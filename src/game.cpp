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
  while (!state->isGameFinished()) {
    state->render();
    cout << "teste" << endl;
  }
}