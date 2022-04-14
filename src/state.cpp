#include "../include/state.h"

State* State::instance;

State::State(){
    isFinished = false;
    board = new Board();
    winner = -1;
    isStarted = true;
}

State::~State(){

}

State& State::getInstance(){
    if (instance != nullptr){
      // std::cout << "Intancia ja existente" << std::endl;
      return *instance;
    }
    else{
        State *state = new State();
        instance = state;
        return *state;
    }
}

void State::start(){
    std::cout << "O jogo de inuncação começou" << std::endl << std::endl;
    if(instance == nullptr){
        getInstance();
    }
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
    std::cout << "passou" << std::endl;
    std::cout << !board->isSpotAvailable(inputParsed, playerNumber) << std::endl;
    std::cout << !plays.empty() << std::endl;
    std::cout << plays.size() << std::endl;
    if(!board->isSpotAvailable(inputParsed, playerNumber) ||
    (!plays.empty() &&
    plays.back().first[0] == inputParsed[0] &&
    plays.back().first[1] == inputParsed[1])) {
        return false;
    } else {
        plays.push(std::make_pair(inputParsed, playerNumber));
        std::cout << "jogada enfileirada" << std::endl;
        return true;
    }
}

void State::resetState() {
    instance = nullptr;
}

void State::render() {
    // std::cout << winner << std::endl;
    std::cout<< "render" << std::endl;
    board->printMap();
    std::cout<< "mapa printado" << std::endl;
    
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