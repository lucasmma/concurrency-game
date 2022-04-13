#include "../include/state.h"

State::State(){
    isFinished = false;
    board = new Board();
}

State::~State(){

}

void State::start(){
    std::cout << "O jogo de inuncação começou" << std::endl << std::endl;
}

void State::update(){
    while (!plays.empty()){
        std::pair<std::vector<int>, int> currentPlay = plays.front();
        board->updateMap(currentPlay.first, currentPlay.second);
        plays.pop();
    }
}

bool State::enqueuePlay(std::vector<int> inputParsed, int playerNumber){
    if(!board->isSpotAvailable(inputParsed) ||
    (!plays.empty() &&
    plays.back().first[0] == inputParsed[0] &&
    plays.back().first[1] == inputParsed[1])) {
        return false;
    } else {
        plays.push(std::make_pair(inputParsed, playerNumber));
        return true;
    }
}

void State::render() {
    board->printMap();
    return;
}

bool State::isGameFinished(){
    return isFinished;
}