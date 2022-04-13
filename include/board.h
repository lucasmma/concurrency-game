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
    bool isSpotAvailable(std::vector<int> spot, int playerNumber);
    void updateMap(std::vector<int> spot, int playerNumber);
    int isFlooded();
    std::vector<int> checkNeighboarsPlayers(int x, int y);
    static int width;
    static int height;
  	
  private:
    int countSpotsWithNumber(int playerNumber);
    int board[8][8];
};



#endif