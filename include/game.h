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
#include <sys/shm.h>
#include <sys/stat.h>
#include <cstdio>
#include <cstring>
#include <semaphore.h>
#include "state.h"

class Game{
public:
    ~Game();
    void run(int playerNumber, bool exit = false);
    static Game& getInstance();
    State& getState();
private:
    Game();
    static Game* instance;
    State* state;
    std::vector<int> handleInput(bool invalidPlay = false);
    int player;
};

#endif