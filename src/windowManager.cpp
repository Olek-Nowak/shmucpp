#include "windowManager.h"
#include "string"
using namespace std;

// TODO: responsive window resizing

windowManager::windowManager() {
    mainWindow = new sf::RenderWindow(sf::VideoMode(900, 600), "shmuCPP");
    mainWindow->setFramerateLimit(60);
    mainWindow->setVerticalSyncEnabled(1);
    mainWindow->clear();
    font.loadFromFile("../resource/arial.ttf");
    trackerHP = 3;

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
    sf::Text hud;
    hud.setFont(font);
    string text = "HP: " + to_string(trackerHP);
    hud.setString(text);
    hud.setCharacterSize(20);
    hud.setFillColor(sf::Color::Green);
    hud.setPosition(50, 550);
    mainWindow->draw(hud);
    mainWindow->display();

}

void windowManager::loseScreen() {
    sf::Text t;
    t.setFont(font);
    t.setString("GAME OVER");
    t.setCharacterSize(40);
    t.setFillColor(sf::Color::Red);
    t.setPosition(320, 250);
    mainWindow->draw(t);
    mainWindow->display();

}

void windowManager::exit() {
    mainWindow->close();

}

void windowManager::updateUI(int delta) {
    trackerHP += delta;

}