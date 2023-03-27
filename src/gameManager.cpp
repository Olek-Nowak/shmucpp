#include "gameManager.h"
using namespace std;

gameManager::gameManager() {
    wep1 = new weapon(2.0f);
    entity player = entity(100, 450, 450, 5, 900, 600, "../resource/1.png", *wep1);
    index_entity.push_front(player);
    p = new pool(50, "../resource/logo.png");
    gameOn_flag = 1;
    
}

gameManager::~gameManager() {
    wm.~windowManager();

}

gameManager& gameManager::getInstance() {
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

void gameManager::update() {
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
        case sf::Keyboard::Space:
            index_projectile.push_back(p->getNew());
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

    // CREATE GAMEOBJECTS

    // MOVE GAMEOBJECTS
    list<entity>::iterator ei = index_entity.begin();
    for(ei; ei != index_entity.end(); ei++) {
        ei->move();

    }
    list<projectile>::iterator pi = index_projectile.begin();
    for(pi; pi != index_projectile.end(); pi++) {
        pi->move();

    }
    
    //player->move();
    //player->setVel_x(0);
    //player->setVel_y(0);


    // DRAW CALLS
    wm.clear();
    for(ei = index_entity.begin(); ei != index_entity.end(); ei++) {
        wm.add(ei->sprite);

    }
    for(pi = index_projectile.begin(); pi != index_projectile.end(); pi++) {
        wm.add(pi->sprite);

    }
    wm.show();

}