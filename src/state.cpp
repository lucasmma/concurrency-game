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

    if(winner != -1){
        isFinished = true;
    }
}

bool State::enqueuePlay(std::vector<int> inputParsed, int playerNumber){
    //so pode até duas jogadas enfileiradas
    // std::cout<< "Jogador  "<< playerNumber<< std::endl;
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
    std::cout << winner << std::endl;
    board->printMap();
    if(winner > 0){
        std::cout << std::endl << "O jogo acabou, e o jogador " << winner << " ganhou." << std::endl;
    } else if(winner == 0){
        std::cout << std::endl << "O jogo acabou com um empate." << std::endl;
    }
    return;
}

bool State::isGameFinished(){
    return isFinished;
}