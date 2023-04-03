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
    windowManager wm = windowManager::getInstance();
    pool* p = nullptr;
    sf::Texture playerTex;
    sf::Texture enemyTex;
    sf::Texture projectileTex;
    std::list<projectile> index_projectile;
    std::list<entity> index_entity;
    float spawnPoints[5];
public:
    bool gameOn_flag;
    ~gameManager();
    static gameManager& getInstance();
    void left_down();
    void right_down();
    void reset_input();
    void pause();
    void update(int msElapsed);
    
};



#endif