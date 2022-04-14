#include "../include/game.h"

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


void Game::run(int playerNumber, bool exit){
  std::cout<< "começando o jogo" << std::endl;
  player = playerNumber;
  size_t idMemoryShared;
  key_t key = ftok("/mnt/c/Users/lukit/Desktop/unb/sisop/concurrency-game/key.txt", 3);
  std::cout << key << std::endl;
  if ((idMemoryShared = shmget(key, sizeof(State), 0666 | IPC_CREAT | IPC_EXCL)) == -1){
    // memoria já está alocada
    idMemoryShared = shmget(key, sizeof(State), 0666 | IPC_CREAT);
    std::cout << idMemoryShared << std::endl;
    char* blkAddr = (char* ) shmat(idMemoryShared, NULL, 0);
    state = (State*) blkAddr;
    std::cout << "entrou no if" << std::endl;
    std::cout << &blkAddr << std::endl;
    std::cout << state << std::endl;
  } else {
    // memoria não alocada
    std::cout << "entrou no else" << std::endl;
    char* blkAddr = (char* ) shmat(idMemoryShared, NULL, 0);
    state = new(blkAddr) State();
  }
  
  if(exit){
    std::cout<< "sair" << std::endl;
    if(-1 == (shmdt(state))){   
        perror("shmdt");
    }
    state->resetState();
    std::cout<< "dettach" << std::endl;
    return;
  }

  state->start();

  state->render();
  while (!state->isGameFinished()) {
    std::cout << std::endl << "Vez do jogador "<< this->player << std::endl;
    std::vector<int> inputHandled = handleInput();
    while(!state->enqueuePlay(inputHandled, this->player)){
      inputHandled = handleInput(true);
    }
    state->update();
    state->render();
  }
  
    shmdt(state);
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