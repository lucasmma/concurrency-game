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
    void render();
    bool isGameFinished();
  	
  private:
    Board *board;
    bool isFinished;
};



#endif