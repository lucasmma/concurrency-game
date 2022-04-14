#ifndef GAME_H
    #include "game.h"
#endif

#ifndef STATE_H
#define STATE_H

class State{
  public:
    State();
    ~State();
    void start();
    void update(std::vector<int> spot, int playerNumber);
    void resetState();
    void render();
    bool isGameFinished();
    void printBoard();
    bool isSpotAvailableOnBoard(std::vector<int> spot, int playerNumber);
    void updateBoard(std::vector<int> spot, int playerNumber);
    int isBoardFlooded();
    std::vector<int> checkNeighboarsPlayersOnBoard(int x, int y);
    static int boardWidth;
    static int boardHeight;
  	
  private:
    int board[8][8];
    int countSpotsWithNumber(int playerNumber);
    int counterPlays;
    bool isStarted;
    bool isFinished;
    int winner;
};

#endif