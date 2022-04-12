#include "../include/state.h"

State::State(){
    isFinished = false;
    board = new Board();
}

State::~State(){

}

void State::start(){
    cout << "O jogo de inuncação começou" << endl << endl;
}

void State::update(){

}

void State::render() {
    board->printMap();
    return;
}

bool State::isGameFinished(){
    return isFinished;
}