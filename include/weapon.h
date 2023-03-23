#ifndef WEAPON
#define WEAPON
#include "projectile.h"

class weapon {
private:
    float cooldown;
    float maxCooldown;
public:
    projectile* p = nullptr;
    weapon(float maxCD, projectile proj);
    bool shoot();

};

#endif