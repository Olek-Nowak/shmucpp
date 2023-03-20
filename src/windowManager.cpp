#include "windowManager.h"
using namespace std;

windowManager::windowManager() {


}

windowManager::~windowManager() {
    mainWindow->close();

}

windowManager& windowManager::getInstance() {
    static windowManager instance;
    return instance;

}

void windowManager::setup(int res[2]) {
    mainWindow = new sf::RenderWindow(sf::VideoMode(res[0], res[1]), "shmuCPP");
    
}

sf::Event windowManager::pollEvents() {
    if (mainWindow->isOpen()) {
        sf::Event newEvent;
        mainWindow->pollEvent(newEvent);
        return newEvent;

    }

}

void windowManager::redraw() {
    mainWindow->clear();

}

void windowManager::testInputs(sf::Color color) {
    mainWindow->clear();
    sf::CircleShape shape(200.0f);
    shape.setFillColor(color);
    mainWindow->draw(shape);
    mainWindow->display();

}