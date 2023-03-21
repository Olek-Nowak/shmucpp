#include "gameManager.h"
using namespace std;

gameManager::gameManager() {
    player = new entity(100, 100, 100, 5, 900, 600, "../resource/logo.png");
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


    // DRAW CALLS
    wm.clear();
    wm.add(player->sprite);
    wm.show();

}

void gameManager::left_down() {
    player->setVel_x(-0.5f);

}

void gameManager::right_down() {
    player->setVel_x(0.5f);

}

void gameManager::pause() {


}