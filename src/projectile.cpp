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
    boundries[0] = 400;
    boundries[1] = 400;

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
    float px = sprite.getPosition().x;
    float py = sprite.getPosition().y;
    // boundries are defined as offsets from centre of screen (900x600)
    /*if(px > 450 + boundries[0])
        sprite.setPosition(450 + boundries[0],py);
    if(px < 450 - boundries[0])
        sprite.setPosition(450 - boundries[0],py);*/
    if(py > 300 + boundries[1])
        setDisabled(true);
    if(py < 300 - boundries[1])
        setDisabled(true);
    sprite.setPosition(px, 450 + boundries[1]);
    sprite.setPosition(px + vel[0], py + vel[1]);
    return 0;

}