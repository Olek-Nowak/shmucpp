#ifndef DRAWABLE
#define DRAWABLE
#include <SFML/Graphics.hpp>

class IDrawable {
protected:
public:
    sf::Sprite sprite;
    bool disabled;
    
};

#endif