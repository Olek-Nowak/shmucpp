#include "gameManager.h"
using namespace std;

// TODO: enemy spawning
// TODO: pause
// TODO: rework allegiance (store separately)
// TODO: entity collision

gameManager::gameManager() {
    weapon basic = weapon(1200);
    weapon noWep = weapon(4000);
    shipTex.loadFromFile("../resource/1.png");
    projectileTex.loadFromFile("../resource/2.png");
    index_entity.push_front(entity(0, 3, 450, 500, 30, 900, 600, shipTex, basic));
    index_entity.push_front(entity(1, 3, 200, 100, 30, 900, 600, shipTex, noWep));
    index_entity.push_front(entity(1, 3, 800, 200, 30, 900, 600, shipTex, noWep));
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
    while(ei != index_entity.end()) {
        pi = index_projectile.begin();
        // destroy
        if(ei->disabled) {
            ei->~entity();
            ei = index_entity.erase(ei);

        }
        else {
        // check collision
            while(pi != index_projectile.end()) {
                // check overlapping between two circle colliders AND take XOR of their allegiance (enemy / friendly)
                if((ei->getDist(pi->sprite.getPosition().x, pi->sprite.getPosition().y) <= ei->getHitbox() + pi->getHitbox()) && (!ei->getEnemy() != !pi->getEnemy())) {
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
        // shoot
            if(ei->wep->shoot(msElapsed)) {
                projectile temp = p->getNew(ei->getEnemy());
                temp.sprite.setPosition(ei->sprite.getPosition());
                index_projectile.push_back(temp);

            }
        // draw
            wm.add(ei->sprite);
        // increment
            ei++;

        }

    }

    for (pi = index_projectile.begin(); pi != index_projectile.end(); pi++) {
        // move
        pi->move();
        // draw
        wm.add(pi->sprite);

    }
    wm.show();

}