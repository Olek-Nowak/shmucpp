#include <SFML/Graphics.hpp>
#include "windowManager.h"
#include "gameManager.h"
using namespace std;

bool gameRunning;
int res[2] = {900, 600};

// main used for init, game loop and integration
int main() {
    gameRunning = 1;
    gameManager gm = gameManager::getInstance();
    windowManager wm = windowManager::getInstance();
    wm.setup(res);
    while(gameRunning) {
        sf::Event e = wm.pollEvents();
        switch (e.type) {
        case sf::Event::Closed:
            gameRunning = 0;
            break;
        case sf::Event::KeyPressed:
            switch (e.key.code) {
            case sf::Keyboard::Left:
                gm.input_left();
                wm.testInputs(sf::Color::Green);
                break;
            case sf::Keyboard::Right:
                gm.input_right();
                wm.testInputs(sf::Color::Red);
                break;
            }
            break;
        }        

    } 

    return 0;
}