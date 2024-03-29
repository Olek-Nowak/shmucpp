#include <chrono>
#include <thread>
#include "gameManager.h"
using namespace std;

chrono::steady_clock::time_point before;
chrono::steady_clock::time_point after;
int sinceLastFrame;

// main used only for game loop and game manager init
int main() {
    sinceLastFrame = 0;
    gameManager gm = gameManager::getInstance();
    while(gm.gameOn()) {
        before = chrono::steady_clock::now();
        gm.update(sinceLastFrame);
        after = chrono::steady_clock::now();
        sinceLastFrame = chrono::duration_cast<chrono::milliseconds>(after - before).count();
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    gm.~gameManager();
    return 0;
}