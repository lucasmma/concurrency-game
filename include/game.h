#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>
#include <queue>
#include <utility>
#include <unistd.h>
#include <thread>
#include <cstdio>
#include <cstring>
#include <semaphore.h>
#include "state.h"
#include <time.h>

class Game{
public:
    ~Game();
    void run(bool autoPlay, int playerNumber);
    static Game& getInstance();
    State& getState();
private:
    Game();
    static Game* instance;
    State* state;
    std::vector<int> handleInput(bool invalidPlay = false);
};

#endif