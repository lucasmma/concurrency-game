#include "../include/state.h"

State::State(){
    isFinished = false;
    board = new Board();
    winner = -1;
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
    
    winner = board->isFlooded();
}

bool State::enqueuePlay(std::vector<int> inputParsed, int playerNumber){
    //so pode até duas jogadas enfileiradas
    if(!board->isSpotAvailable(inputParsed, playerNumber) ||
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
    if(winner == -1){
        board->printMap();
    } else{
        std::cout << std::endl << "O jogo acabou" << std::endl;
    }
    return;
}

bool State::isGameFinished(){
    return isFinished;
}