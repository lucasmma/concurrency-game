#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>
#include <queue>
#include <utility>
#include "board.h"
#include "state.h"

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
    std::vector<int> handleInput(bool invalidPlay = false);
    bool primaryPlayer;

};

#endif