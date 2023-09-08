#ifndef GAME
#define GAME
#include "singleton.h"
#include "windowManager.h"
#include "ship.h"
#include "projectile.h"
#include "pool.h"
#include <list>

class gameManager : singleton {
private:
    gameManager();
    windowManager wm = windowManager::getInstance();
    pool* p = nullptr;
    sf::Texture shipTex;
    sf::Texture projectileTex;
    std::list<entity*> team_0;
    std::list<entity*> team_1;
    float spawnPoints[5];
    bool gameOn_flag;
    projectile* testp = nullptr;
public:
    ~gameManager();
    bool gameOn();
    static gameManager& getInstance();
    void left_down();
    void right_down();
    void reset_input();
    void pause();
    void update(int msElapsed);
    
};



#endif