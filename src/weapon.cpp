#include "weapon.h"
using namespace std;

weapon::weapon(int maxCD) {
    maxCooldown = maxCD;
    cooldown = maxCooldown;

}

bool weapon::shoot(int frameTime) {
    if(maxCooldown <= 0)
        return 0;
    cooldown -= frameTime;
    if(cooldown <= 0) {
        cooldown = maxCooldown;
        return 1;

    }
    else return 0;

}