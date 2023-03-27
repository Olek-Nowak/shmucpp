#ifndef WEAPON
#define WEAPON
#include "projectile.h"

class weapon {
private:
    float cooldown;
    float maxCooldown;
public:
    weapon(float maxCD);
    bool shoot();

};

#endif