#include "windowManager.h"
using namespace std;

windowManager::windowManager() {
    mainWindow = new sf::RenderWindow(sf::VideoMode(900, 600), "shmuCPP");
    mainWindow->clear();

}

windowManager::~windowManager() {
    mainWindow->close();

}

windowManager& windowManager::getInstance() {
    static windowManager instance;
    return instance;

}

sf::Event windowManager::pollEvents() {
    if (mainWindow->isOpen()) {
        sf::Event newEvent;
        mainWindow->pollEvent(newEvent);
        return newEvent;

    }

}

void windowManager::clear() {
    mainWindow->clear();

}

void windowManager::add(sf::Sprite s) {
    mainWindow->draw(s);

}

void windowManager::show() {
    mainWindow->display();

}