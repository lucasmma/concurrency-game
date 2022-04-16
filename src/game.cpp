#include "../include/game.h"

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

void Game::run(bool autoPlay, int playerNumber){
  state->start(!autoPlay);
  if(!autoPlay) {
    sem_wait(&(state->sem));
    state->render();
    sem_post(&(state->sem));
  }
  sem_wait(&(state->sem));
  while (!state->isGameFinished()) {
    sem_post(&(state->sem));
    sem_wait(&(state->cinSem));
    if(!autoPlay) {
      sem_wait(&(state->sem));
      state->render();
      sem_post(&(state->sem));
    }
    sem_wait(&(state->sem));
    if(state->isGameFinished()){
      sem_post(&(state->sem));
      return;
    }
    std::vector<int> inputHandled;
    sem_wait(&(state->sem));
    if(!autoPlay){
      std::cout << std::endl << "Vez do jogador "<< playerNumber << std::endl;
      inputHandled = handleInput();
      while(!state->isSpotAvailableOnBoard(inputHandled, playerNumber)){
        inputHandled = handleInput(true);
      }
    } else if(state->playsCounter != 0){
      std::cout << std::endl << "AutoPlay" << std::endl;
      inputHandled = state->autoPlay(playerNumber);
    }
    sem_post(&(state->cinSem));
    sem_post(&(state->sem));
    
    sem_wait(&(state->sem));
    state->update(inputHandled, playerNumber);
    sem_post(&(state->sem));

    if(!autoPlay) {
      sem_wait(&(state->sem));
      state->render();
      sem_post(&(state->sem));
    }

    sem_wait(&(state->sem));
    if(state->isGameFinished()){
      sem_post(&(state->sem));
    }
    
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
    if (axisInput[0] >= State::boardWidth || axisInput[1] >= State::boardHeight){
      std::cout << "Deve ser digitado apenas números de 0 a 7" << std::endl;
      return handleInput();
    }
  }

  return axisInput;
}