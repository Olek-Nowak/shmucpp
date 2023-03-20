#include "gameManager.h"
using namespace std;

gameManager::gameManager() {

    
}

gameManager::~gameManager() {


}

gameManager& gameManager::getInstance() {
    static gameManager instance;
    return instance;

}

void gameManager::input_left() {


}

void gameManager::input_right() {


}

void gameManager::pause() {


}