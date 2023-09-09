#include <cmath>
#include "projectile.h"
using namespace std;

projectile::projectile(sf::Texture &res) {
    disabled = 0;
    hitboxRadius = 5.0f;
    sprite = sf::Sprite(res);
    sprite.setOrigin(res.getSize().x / 2, res.getSize().y / 2);
    sprite.setPosition(0.0f, 0.0f);
    setVel_x(0.0f);
    setVel_y(0.0f);

}

bool projectile::checkCollision(entity* e) {
    // Checks if collision is between two projectiles - then no collision
    if(e->getHitbox() < 6.0f)
        return false;
    float dist = sqrtf(powf((sprite.getPosition().x - e->sprite.getPosition().x), 2.0f) + powf((sprite.getPosition().y - e->sprite.getPosition().y), 2.0f));
    if(dist <= hitboxRadius + e->getHitbox()) {
        disabled = true;
        return true;

    }
    else return false;

}

bool projectile::update(int msElapsed) {
    /*if(pos[0] > boundries[0])
    pos[0] = boundries[0];
    if(pos[1] > boundries[1])
    pos[1] = boundries[1];*/
    sprite.setPosition(sprite.getPosition().x + vel[0], sprite.getPosition().y + vel[1]);
    return 0;

}