#ifndef GAME
#define GAME
#include "singleton.h"
#include "windowManager.h"
#include "entity.h"
#include "weapon.h"
#include "projectile.h"

class gameManager : singleton {
private:
    gameManager();
    projectile* proj1 = nullptr;
    weapon* wep1 = nullptr;
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