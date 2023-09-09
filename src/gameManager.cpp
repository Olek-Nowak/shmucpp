#include "gameManager.h"
#include <iostream>
using namespace std;

// TODO: enemy spawning
// TODO: pause
// TODO: entity collision
// TODO: game over state

gameManager::gameManager() {
    shipTex.loadFromFile("../resource/1.png");
    projectileTex.loadFromFile("../resource/2.png");
    p = new pool(100, projectileTex);
    entity* newShip = new ship(3, 450.0f, 500.0f, 30.0f, shipTex, 1200);
    team_0.push_front(newShip);
    // temp spawning for testing
    newShip = new ship(2, 200.0f, 100.0f, 30.0f, shipTex, 2000);
    newShip->sprite.setRotation(180);
    newShip->setVel_y(0.0f);
    team_1.push_front(newShip);
    newShip = new ship(1, 800.0f, 50.0f, 30.0f, shipTex, -1);
    newShip->sprite.setRotation(180);
    newShip->setVel_y(1.8f);
    team_1.push_front(newShip);

    gameOn_flag = 1;
    /*for(int i = 0; i < 5; i++) {
        spawnPoints[i] = 50 + i * (600 - 100) / 4;

    }*/

}

gameManager::~gameManager() {
    delete p;
    wm.~windowManager();

}

gameManager &gameManager::getInstance() {
    static gameManager instance;
    return instance;

}

bool gameManager::gameOn() {
    return gameOn_flag;

}

void gameManager::left_down() {
    // Player ship is always the oldest entity in team 0 list
    team_0.back()->setVel_x(-3.0f);

}

void gameManager::right_down() {
    team_0.back()->setVel_x(3.0f);

}

void gameManager::reset_input() {
    team_0.back()->setVel_x(0.0f);

}

void gameManager::pause() {

}

void gameManager::update(int msElapsed) {
    wm.clear();
    // EVENT MANAGEMENT
    sf::Event e = wm.pollEvents();
    switch (e.type)
    {
    case sf::Event::Closed:
        gameOn_flag = 0;
        wm.exit();
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
                // debug
                //team_0.back()->sprite.setRotation(team_0.back()->sprite.getRotation() + 180);
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


    // UPDATE GAMEOBJECTS

    list<entity*>::iterator t0 = team_0.begin();
    list<entity*>::iterator t1 = team_1.begin();
    while(t0 != team_0.end()) {
        // destroy
        if((*t0)->getDisabled()) {
            // handles ship destruction
            if((*t0)->getHitbox() > 6.0f)
                delete (*t0);
            t0 = team_0.erase(t0);

        }
        else {
        // check collision
            t1 = team_1.begin();
            for(t1; t1 != team_1.end(); t1++) {
                (*t0)->checkCollision(*t1);

            }
        // move and shoot
            if((*t0)->update(msElapsed)) {
                entity* temp = p->getNew();
                temp->sprite.setPosition((*t0)->sprite.getPosition());
                temp->setVel_y(-3.6f);
                team_0.push_front(temp);

            }
        // draw
            wm.add((*t0)->sprite);
        // increment
            t0++;

        }

    }

    // Sadly, all collisions will have to be checked twice
    t1 = team_1.begin();
    while(t1 != team_1.end()) {
        // destroy
        if((*t1)->getDisabled()) {
            t1 = team_1.erase(t1);

        }
        else {
        // check collision
            t0 = team_0.begin();
            for(t0; t0 != team_0.end(); t0++) {
                (*t1)->checkCollision(*t0);

            }
        // move and shoot
            if((*t1)->update(msElapsed)) {
                entity* temp = p->getNew();
                temp->sprite.setPosition((*t1)->sprite.getPosition());
                temp->sprite.setRotation(180);
                temp->setVel_y(3.6f);
                team_1.push_front(temp);

            }
        // draw
            wm.add((*t1)->sprite);
        // increment
            t1++;

        }

    }
    wm.show();

    if(team_0.back()->getDisabled()) {
        // Lose state
        gameOn_flag = false;
        wm.loseScreen();

    }

}