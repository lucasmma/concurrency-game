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
    void resetState();
    bool enqueuePlay(std::vector<int> inputParsed, int playerNumber);
    void render();
    bool isGameFinished();
    static State& getInstance();
  	
  private:
    static State* instance;
    std::queue<std::pair<std::vector<int>, int>> plays;
    bool isStarted;
    Board *board;
    bool isFinished;
    int winner;
};



#endif