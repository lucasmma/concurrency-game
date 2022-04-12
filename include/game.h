#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "state.h"
using namespace std;

class Game{
public:
    ~Game();
    void run();
    static Game& getInstance();
    State& getState();
private:
    Game();
    static Game* instance;
    State* state;

};

#endif