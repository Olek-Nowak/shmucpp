#ifndef PROJECTILE
#define PROJECTILE
#include "entity.h"

class projectile : public entity {
private:
public:
    projectile(sf::Texture &res);
    bool checkCollision(entity* e) override;
    bool update(int msElapsed) override;

};

#endif