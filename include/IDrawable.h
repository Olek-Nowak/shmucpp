#ifndef DRAWABLE
#define DRAWABLE
#include <SFML/Graphics.hpp>

class IDrawable {
protected:
    bool enemy;
public:
    sf::Sprite sprite;
    bool disabled;
    virtual bool getEnemy() = 0;
    virtual void setEnemy(bool e) = 0;
    
};

#endif