#ifndef DRAWABLE
#define DRAWABLE
#include <SFML/Graphics.hpp>

class IDrawable {
protected:
    bool disabled;
public:
    sf::Sprite sprite;
    
};

#endif