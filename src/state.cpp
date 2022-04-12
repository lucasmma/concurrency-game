#include "../include/state.h"

State::State(){
    isFinished = false;
}

State::~State(){

}

void State::start(){
    cout << "O jogo de inuncação começou" << endl;
}

void State::update(){

}

void State::render(){

}

bool State::isGameFinished(){
    return isFinished;
}