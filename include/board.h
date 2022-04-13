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
    bool isSpotAvailable(std::vector<int> spot);
    void updateMap(std::vector<int> spot, int playerNumber);
    static int width;
    static int height;
  	
  private:
    int board[8][8];
};



#endif