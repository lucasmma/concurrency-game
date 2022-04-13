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
    void update();
    bool enqueuePlay(std::vector<int> inputParsed, int playerNumber);
    void render();
    bool isGameFinished();
  	
  private:
    std::queue<std::pair<std::vector<int>, int>> plays;
    Board *board;
    bool isFinished;
};



#endif