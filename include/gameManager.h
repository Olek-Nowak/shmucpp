#ifndef GAME
#define GAME
#include "singleton.h"
#include "windowManager.h"
#include "entity.h"
#include "weapon.h"
#include "projectile.h"
#include "pool.h"
#include <list>

class gameManager : singleton {
private:
    gameManager();
    weapon* wep1 = nullptr;
    windowManager wm = windowManager::getInstance();
    pool* p = nullptr;
    std::list<projectile> index_projectile;
    std::list<entity> index_entity;
public:
    bool gameOn_flag;
    ~gameManager();
    static gameManager& getInstance();
    void left_down();
    void right_down();
    void reset_input();
    void pause();
    void update();
    
};



#endif