#ifndef PROJECTILE
#define PROJECTILE
#include "entity.h"

class projectile : public entity {
private:
public:
    sf::Sprite sprite;
    projectile(sf::Texture &res);
    bool checkCollision(entity e);
    bool update(int msElapsed);

};

#endif