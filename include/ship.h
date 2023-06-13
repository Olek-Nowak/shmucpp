#ifndef SHIP
#define SHIP
#include "entity.h"
#include "IDamageable.h"

class ship : public entity, IDamageable {
private:
    int maxHealth;
    int health;
    int maxCD;
    int cooldown;
public:
    ship(int hp, float startx, float starty, float hitbox, float boundryx, float boundryy, sf::Texture &res, int weaponCD);
    ~ship();
    bool checkCollision(entity e);
    void onHit(int damage);
    void destroy();
    bool update(int msElapsed);

};

#endif