#ifndef DRAWABLE
#define DRAWABLE
#include <SFML/Graphics.hpp>

class IDrawable {
protected:
    sf::Texture texture;
public:
    sf::Sprite sprite;
};

#endif