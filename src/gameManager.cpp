#include "gameManager.h"
using namespace std;

gameManager::gameManager() {
    proj1 = new projectile(1, 1.5f, 100, 100, 2, "../resource/logo.png");
    wep1 = new weapon(2.0f, *proj1);
    player = new entity(100, 450, 450, 5, 900, 600, "../resource/logo.png", *wep1);
    gameOn_flag = 1;
    
}

gameManager::~gameManager() {
    wm.~windowManager();

}

gameManager& gameManager::getInstance() {
    static gameManager instance;
    return instance;

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
            // wm.testInputs(sf::Color::Green);
            break;
        case sf::Keyboard::Right:
            right_down();
            // wm.testInputs(sf::Color::Red);
            break;
        }
        break;
    }

    // UPDATE GAMEOBJECTS
    player->move();
    player->setVel_x(0);
    player->setVel_y(0);
    proj1->move();


    // DRAW CALLS
    wm.clear();
    wm.add(player->sprite);
    wm.add(proj1->sprite);
    wm.show();

}

void gameManager::left_down() {
    player->setVel_x(-1.0f);

}

void gameManager::right_down() {
    player->setVel_x(1.0f);

}

void gameManager::pause() {


}