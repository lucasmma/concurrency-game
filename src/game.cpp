#include "../include/Game.h"

Game* Game::instance;

Game::Game(){

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
  cout << "hello world" << endl;
}