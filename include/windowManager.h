#ifndef WINDOW
#define WINDOW
#include <SFML/Graphics.hpp>
#include "singleton.h"

/// @remark Sadly, input detection in SFML is tied to window listeners, so inputManager is merged into windowManager.
class windowManager : Singleton {
private:
    sf::RenderWindow* mainWindow;
    windowManager();
public:
    ~windowManager();
    static windowManager& getInstance();
    void setup(int res[2]);
    sf::Event pollEvents();
    void redraw();
    void testInputs(sf::Color color);
    
};



#endif