#include <cmath>
#include "projectile.h"
using namespace std;

projectile::projectile(sf::Texture &res) {
    disabled = 1;
    hitboxRadius = 5.0f;
    sprite = sf::Sprite(res);
    sprite.setOrigin(res.getSize().x / 2, res.getSize().y / 2);
    sprite.setPosition(0.0f, 0.0f);
    setVel_x(0.0f);
    setVel_y(0.0f);

}

bool projectile::checkCollision(entity e) {
    float dist = sqrtf(powf((sprite.getPosition().x - e.sprite.getPosition().x), 2.0f) + powf((sprite.getPosition().y - e.sprite.getPosition().y), 2.0f));
    /*if(dist <= hitboxRadius + e.getHitbox()) {
        // Checks if collision is between two projectiles - then no collision
        if(e.getDisabled()) {
            disabled = false;
            e.setDisabled(false);
            return false;

        }
        disabled = true;
        return true;

    }
    else*/ return false;

}

bool projectile::update(int msElapsed) {
    /*if(pos[0] > boundries[0])
    pos[0] = boundries[0];
    if(pos[1] > boundries[1])
    pos[1] = boundries[1];*/
    sprite.setPosition(sprite.getPosition().x + vel[0] * msElapsed, sprite.getPosition().y + vel[1] * msElapsed);
    return false;

}