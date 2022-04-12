#include "board.h"

Board::Board(){
  for (int i = 0; i < width; i++){
    for (int j = 0; j < height; j++){
      board[i][j] = 0;
    }
  }
  
}


void Board::printMap(){
  cout << "   ";
  for (int i = 0; i < width; i++){
    cout << " " << i;
  }
  
  cout << endl << endl;

  for (int i = 0; i < height; i++){
    cout << i << "  "; 
    for (int j = 0; j < width; j++){
      cout << " " << board[i][j];
    }
    cout << endl;
  }
}

Board::~Board(){

}