#include "gameManager.h"
using namespace std;

// TODO: enemy spawning
// TODO: pause
// TODO: entity destruction

gameManager::gameManager() {
    weapon wep1 = weapon(500);
    entity* player = new entity(100, 450, 400, 5, 900, 600, "../resource/1.png", wep1);
    index_entity.push_front(*player);
    p = new pool(100, "../resource/logo.png");
    gameOn_flag = 1;
    for(int i = 0; i < 5; i++) {
        spawnPoints[i] = 50 + i * (600 - 100) / 4;

    }

}

gameManager::~gameManager() {
    wm.~windowManager();

}

gameManager &gameManager::getInstance() {
    static gameManager instance;
    return instance;

}

void gameManager::left_down() {
    index_entity.front().setVel_x(-1.0f);

}

void gameManager::right_down() {
    index_entity.front().setVel_x(1.0f);

}

void gameManager::reset_input() {
    index_entity.front().setVel_x(0.0f);

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


    // UPDATE GAMOBJECTS - MOVING SHOOTING, DRAWING

    wm.clear();
    list<entity>::iterator ei = index_entity.begin();
    for(ei; ei != index_entity.end(); ei++) {
        ei->move();
        if(ei->wep->shoot(msElapsed)) {
            projectile temp = p->getNew();
            temp.sprite.setPosition(ei->sprite.getPosition() - sf::Vector2f(0.0f, 170.0f));
            index_projectile.push_back(temp);

        }
        wm.add(ei->sprite);

    }
    list<projectile>::iterator pi = index_projectile.begin();
    for (pi; pi != index_projectile.end(); pi++) {
        pi->move();
        wm.add(pi->sprite);

    }
    wm.show();

}