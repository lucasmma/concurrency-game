#ifndef GAME_H
    #include "game.h"
#endif

#ifndef BOARD_H
#define BOARD_H

class Board{
  public:
    Board();
    ~Board();
    void printMap();
  	
  private:
    int width = 8;
    int height = 8;
    int board[8][8];
};



#endif