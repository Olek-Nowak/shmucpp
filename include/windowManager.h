#ifndef WINDOW
#define WINDOW
#include <SFML/Graphics.hpp>
#include "singleton.h"

/// @remark Sadly, input detection in SFML is tied to window listeners, so inputManager is merged into windowManager.
class windowManager : singleton {
private:
    sf::RenderWindow* mainWindow;
    sf::Font font;
    windowManager();
public:
    ~windowManager();
    static windowManager& getInstance();
    sf::Event pollEvents();
    void clear();
    void add(sf::Sprite s);
    void show();
    void loseScreen();
    void exit();
    
};

#endif