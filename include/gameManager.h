#ifndef GAME
#define GAME
#include "singleton.h"
#include "entity.h"
#include "windowManager.h"

class gameManager : singleton {
private:
    gameManager();
    entity* player = nullptr;
    windowManager wm = windowManager::getInstance();
public:
    bool gameOn_flag;
    ~gameManager();
    static gameManager& getInstance();
    void update();
    void left_down();
    void right_down();
    void pause();

};



#endif