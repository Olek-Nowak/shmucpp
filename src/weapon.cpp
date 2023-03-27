#include "weapon.h"
using namespace std;

weapon::weapon(float maxCD) {
    maxCooldown = maxCD;
    cooldown = maxCooldown;

}

bool weapon::shoot() {
    cooldown--;
    if(cooldown <= 0) {
        cooldown = maxCooldown;
        return 1;

    }
    else return 0;

}