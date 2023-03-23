#include "weapon.h"
using namespace std;

weapon::weapon(float maxCD, projectile proj) {
    maxCooldown = maxCD;
    cooldown = maxCooldown;
    p = new projectile(proj);

}

bool weapon::shoot() {
    cooldown--;
    if(cooldown <= 0) {
        cooldown = maxCooldown;
        return 1;

    }
    else return 0;

}