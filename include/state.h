#ifndef GAME_H
    #include "game.h"
#endif

#ifndef STATE_H
#define STATE_H

class State{
  public:
    State();
    ~State();
    void initState();
    void update(std::vector<int> spot, int playerNumber);
    void resetState();
    void render();
    std::vector<int> autoPlay(int playerNumber);
    std::vector<std::vector<int>> spotsAvailableForPlayer(int playerNumber);
    bool isGameFinished();
    void printBoard();
    bool isSpotAvailableOnBoard(std::vector<int> spot, int playerNumber);
    void updateBoard(std::vector<int> spot, int playerNumber);
    int isBoardFlooded();
    std::vector<int> checkNeighboarsPlayersOnBoard(int x, int y);
    static int boardWidth;
    static int boardHeight;
    bool isStarted;
    sem_t cinSem;
    sem_t sem;
    int playsCounter;
  	
  private:
    int board[8][8];
    int countSpotsWithNumber(int playerNumber);
    bool isFinished;
    int winner;
};

#endif