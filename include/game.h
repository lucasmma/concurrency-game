#ifndef GAME_H
#define GAME_H
#include <iostream>
using namespace std;

class Game{
public:
    ~Game();
    void run();
    static Game& getInstance();

private:
    Game();
    static Game* instance;

};

#endif