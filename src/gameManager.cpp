#include "gameManager.h"
using namespace std;

// TODO: enemy spawning
// TODO: pause
// TODO: enemy bullets

gameManager::gameManager() {
    weapon basic = weapon(1200);
    weapon noWep = weapon(-1);
    playerTex.loadFromFile("../resource/1.png");
    enemyTex.loadFromFile("../resource/1.png");
    projectileTex.loadFromFile("../resource/logo.png");
    index_entity.push_front(entity(5, 450, 500, 50, 900, 600, playerTex, basic));
    index_entity.push_front(entity(2, 200, 100, 50, 900, 600, enemyTex, noWep));
    p = new pool(100, projectileTex);
    gameOn_flag = 1;
    for(int i = 0; i < 5; i++) {
        spawnPoints[i] = 50 + i * (600 - 100) / 4;

    }

}

gameManager::~gameManager() {
    delete p;
    wm.~windowManager();

}

gameManager &gameManager::getInstance() {
    static gameManager instance;
    return instance;

}

void gameManager::left_down() {
    index_entity.back().setVel_x(-4.0f);

}

void gameManager::right_down() {
    index_entity.back().setVel_x(4.0f);

}

void gameManager::reset_input() {
    index_entity.back().setVel_x(0.0f);

}

void gameManager::pause() {

}

void gameManager::update(int msElapsed) {
    // EVENT MANAGEMENT

    sf::Event e = wm.pollEvents();
    switch (e.type)
    {
    case sf::Event::Closed:
        gameOn_flag = 0;
        break;
    case sf::Event::KeyPressed:
        switch (e.key.code)
        {
        case sf::Keyboard::Left:
            left_down();
            break;
        case sf::Keyboard::Right:
            right_down();
            break;
        }
        break;
    case sf::Event::KeyReleased:
        switch (e.key.code)
        {
        case sf::Keyboard::Left:
            reset_input();
            break;
        case sf::Keyboard::Right:
            reset_input();
            break;
        }
        break;
    }

    // SPAWN NEW ENEMIES


    // UPDATE GAMOBJECTS

    wm.clear();
    list<entity>::iterator ei = index_entity.begin();
    list<projectile>::iterator pi = index_projectile.begin();
    for(ei; ei != index_entity.end(); ei++) {
        // destroy
        if(ei->disabled) {
            ei->~entity();
            ei = index_entity.erase(ei);

        }
        // check collision
        while(pi != index_projectile.end()) {
            if(ei->getDist(pi->sprite.getPosition().x, pi->sprite.getPosition().y) <= ei->getHitbox() + pi->getHitbox()) {
                pi->disabled = 1;
                ei->onHit(pi->getDamage());
                pi = index_projectile.erase(pi);

            }
            else {
                pi++;

            }

        }
        // move
        ei->move();
        //shoot
        if(ei->wep->shoot(msElapsed)) {
            projectile temp = p->getNew();
            temp.sprite.setPosition(ei->sprite.getPosition() - sf::Vector2f(0.0f, 170.0f));
            index_projectile.push_back(temp);

        }
        // draw
        wm.add(ei->sprite);

    }
    for (pi = index_projectile.begin(); pi != index_projectile.end(); pi++) {
        // move
        pi->move();
        // draw
        wm.add(pi->sprite);

    }
    wm.show();

}