#ifndef WEAPON
#define WEAPON
#include "projectile.h"

class weapon {
private:
    int cooldown;
    int maxCooldown;
public:
    weapon(int maxCD);
    bool shoot(int frameTime);

};

#endif