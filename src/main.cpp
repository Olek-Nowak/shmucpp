#include <SFML/Graphics.hpp>
#include "gameManager.h"
using namespace std;

// main used only for game loop and game manager init
int main() {
    gameManager gm = gameManager::getInstance();
    while(gm.gameOn_flag) {
        gm.update();

    }
    gm.~gameManager();

    return 0;
}