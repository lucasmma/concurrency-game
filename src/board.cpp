#include "board.h"

int Board::width = 8;
int Board::height = 8;

Board::Board(){
  for (int i = 0; i < width; i++){
    for (int j = 0; j < height; j++){
      board[i][j] = 0;
    }
  }
  
}

bool Board::isSpotAvailable(std::vector<int> spot){
  return board[spot[0]][spot[1]] == 0;
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