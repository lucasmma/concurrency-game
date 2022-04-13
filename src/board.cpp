#include "board.h"

int Board::width = 8;
int Board::height = 8;

Board::Board(){
  for (int i = 0; i < width; i++){
    for (int j = 0; j < height; j++){
      board[i][j] = 0;
      if(i != 7) {
        board[i][j] = 2;
      }
    }
  }
  
  board[Board::width - 1][Board::height - 1] = 1;
}

bool Board::isSpotAvailable(std::vector<int> spot, int playerNumber){
  // std::cout << (board[spot[0]][spot[1]] == 0) << " is available";
  if (board[spot[0]][spot[1]] == 0) {
    std::vector<int> playersNeighboars= checkNeighboarsPlayers(spot[0], spot[1]);
  
    for (long unsigned int i = 0; i < playersNeighboars.size(); i++){
      if(playerNumber == playersNeighboars[i]){
        return true;
      } 
    }
    return false;
  }

  return false;
}

std::vector<int> Board::checkNeighboarsPlayers(int x, int y){
  std::vector<std::pair<int, int>> neighboarsAxis = {std::make_pair(-1, 0), std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(0, -1)};
  std::vector<int> playersNeighboars = {};
  for (long unsigned int i = 0; i < neighboarsAxis.size(); i++){
    if(!(x + neighboarsAxis[i].first < 0 || y + neighboarsAxis[i].second < 0 || x + neighboarsAxis[i].first == Board::width || y + neighboarsAxis[i].second == Board::height)){
      playersNeighboars.push_back(board[x + neighboarsAxis[i].first][y + neighboarsAxis[i].second]);
    }
  }
  
  return playersNeighboars;
}

int Board::countSpotsWithNumber(int playerNumber){
  int spots = 0;
  for (int i = 0; i < width; i++){
    for (int j = 0; j < height; j++){
      if(board[i][j] == playerNumber) {
        spots++;
      }
    }
  }

  // std::cout << "Spots player " << playerNumber << " -> " << spots << std::endl;
  
  return spots;
}

int Board::isFlooded(){
  int spotsToPlayer1 = 0;
  int spotsToPlayer2 = 0;
  for (int i = 0; i < Board::width; i++){
    for (int j = 0; j < Board::height; j++){
      if(board[i][j] == 0){
        std::vector<int> neighboars = checkNeighboarsPlayers(i, j);
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

void Board::updateMap(std::vector<int> spot, int playerNumber){
  board[spot[0]][spot[1]] = playerNumber;
}

void Board::printMap(){
  std::cout << "   ";
  for (int i = 0; i < width; i++){
    std::cout << " " << i;
  }
  
  std::cout << std::endl << std::endl;

  for (int i = 0; i < height; i++){
    std::cout << i << "  "; 
    for (int j = 0; j < width; j++){
      std::cout << " " << board[i][j];
    }
    std::cout << std::endl;
  }
}

Board::~Board(){

}