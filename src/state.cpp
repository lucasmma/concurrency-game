#include "../include/state.h"


int State::boardWidth = 8;
int State::boardHeight = 8;

State::State(){
    isFinished = false;
    winner = -1;
    isStarted = true;
        for (int i = 0; i < State::boardWidth; i++){
        for (int j = 0; j < State::boardHeight; j++){
        board[i][j] = 0;
        if(i != 7) {
            board[i][j] = 2;
        }
        }
    }
    
    sem_init(&sem, 1, 1);
    playsCounter = 0;
    board[State::boardWidth - 1][State::boardHeight - 1] = 1;
}

State::~State(){

}

void State::start(){
    std::cout << "O jogo de inuncação começou" << std::endl << std::endl;
    std::cout << "Jogo iniciado " << isStarted << std::endl;
    std::cout << "IsFinished " << isFinished << std::endl;
    std::cout << "winner " << winner << std::endl;
    std::cout << "passou " << std::endl << std::endl;
    
    if(!isStarted){
        isFinished = false;
        for (int i = 0; i < State::boardWidth; i++){
            for (int j = 0; j < State::boardHeight; j++){
            board[i][j] = 0;
            if(i != 7) {
                board[i][j] = 2;
            }
            }
        }
        
        sem_init(&sem, 1, 1);
        sem_init(&cinSem, 1, 1);
        board[State::boardWidth - 1][State::boardHeight - 1] = 1;
        winner = -1;
        isStarted = true;
        playsCounter = 0;
    }
}

void State::update(std::vector<int> spot, int playerNumber){
    updateBoard(spot, playerNumber);
    playsCounter++;
    winner = isBoardFlooded();

    if(winner != -1){
        isFinished = true;
    }
}

void State::resetState() {
    isStarted = false;
    sem_destroy(&sem);
    sem_destroy(&cinSem);
}

void State::render() {
    // std::cout << winner << std::endl;
    // std::cout<< "render" << std::endl;
    printBoard();
    // std::cout<< "mapa printado" << std::endl;
    
    if(winner > 0){
        std::cout << std::endl << "O jogo acabou, e o jogador " << winner << " ganhou." << std::endl;
    } else if(winner == 0){
        std::cout << std::endl << "O jogo acabou com um empate." << std::endl;
    }
    return;
}

bool State::isGameFinished(){
    return isFinished;
}

// Board functions

bool State::isSpotAvailableOnBoard(std::vector<int> spot, int playerNumber){
  // std::cout << (board[spot[0]][spot[1]] == 0) << " is available";
  if (board[spot[0]][spot[1]] == 0) {
    std::vector<int> playersNeighboars= checkNeighboarsPlayersOnBoard(spot[0], spot[1]);
  
    for (long unsigned int i = 0; i < playersNeighboars.size(); i++){
      if(playerNumber == playersNeighboars[i]){
        return true;
      } 
    }
    return false;
  }

  return false;
}

std::vector<int> State::checkNeighboarsPlayersOnBoard(int x, int y){
  std::vector<std::pair<int, int>> neighboarsAxis = {std::make_pair(-1, 0), std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(0, -1)};
  std::vector<int> playersNeighboars = {};
  for (long unsigned int i = 0; i < neighboarsAxis.size(); i++){
    if(!(x + neighboarsAxis[i].first < 0 || y + neighboarsAxis[i].second < 0 || x + neighboarsAxis[i].first == State::boardWidth || y + neighboarsAxis[i].second == State::boardHeight)){
      playersNeighboars.push_back(board[x + neighboarsAxis[i].first][y + neighboarsAxis[i].second]);
    }
  }
  
  return playersNeighboars;
}

int State::countSpotsWithNumber(int playerNumber){
  int spots = 0;
  for (int i = 0; i < State::boardWidth; i++){
    for (int j = 0; j < State::boardHeight; j++){
      if(board[i][j] == playerNumber) {
        spots++;
      }
    }
  }

  // std::cout << "Spots player " << playerNumber << " -> " << spots << std::endl;
  
  return spots;
}

int State::isBoardFlooded(){
  int spotsToPlayer1 = 0;
  int spotsToPlayer2 = 0;
  for (int i = 0; i < State::boardWidth; i++){
    for (int j = 0; j < State::boardHeight; j++){
      if(board[i][j] == 0){
        std::vector<int> neighboars = checkNeighboarsPlayersOnBoard(i, j);
        for (long unsigned int i = 0; i < neighboars.size(); i++){
          if(neighboars[i] != 0) {
            if(neighboars[i] == 1){
              spotsToPlayer1++;
            } else{
              spotsToPlayer2++;
            }
          }
        }
      }
    }
  }
  
  // std::cout << "Spots player 1" << " -> " << spotsToPlayer2 << std::endl;
  // std::cout << "Spots player 2" << " -> " << spotsToPlayer2 << std::endl;

  if(spotsToPlayer1 == 0 || spotsToPlayer2 == 0){
    int spotsOfPlayer1 = countSpotsWithNumber(1);
    int spotsOfPlayer2 = countSpotsWithNumber(2);
    if(spotsOfPlayer1 > spotsOfPlayer2){
      return 1;
    } else if(spotsOfPlayer1 < spotsOfPlayer2){
      return 2;
    } else{
      return 0;
    }
  }
  
  return -1;
  
  // return 0 if draw, and -1 if is not flooded
  // return 1 if player 1 wins, and 2 if player 2 wins
}

void State::updateBoard(std::vector<int> spot, int playerNumber){
  board[spot[0]][spot[1]] = playerNumber;
}

void State::printBoard(){
  std::cout << "   ";
  for (int i = 0; i < State::boardWidth; i++){
    std::cout << " " << i;
  }
  
  std::cout << std::endl << std::endl;

  for (int i = 0; i < State::boardWidth; i++){
    std::cout << i << "  "; 
    for (int j = 0; j < State::boardHeight; j++){
      std::cout << " " << board[i][j];
    }
    std::cout << std::endl;
  }
}