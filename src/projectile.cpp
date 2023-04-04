#include <cmath>
#include "projectile.h"
using namespace std;

projectile::projectile(sf::Texture &res) {
    disabled = 1;
    hitboxRadius = 5.0f;
    damage = 1;
    shootSpeed = 3.0f;
    sprite = sf::Sprite(res);
    sprite.setOrigin(res.getSize().x / 2, res.getSize().y / 2);
    sprite.setPosition(0.0f, 0.0f);
    setVel_x(0.0f);
    setVel_y(-1.0f * shootSpeed);

}

void projectile::setVel_x(float vx) {
    vel[0] = vx;

}

void projectile::setVel_y(float vy) {
    vel[1] = vy;

}

float projectile::getDist(float x, float y) {
    return sqrtf(powf((sprite.getPosition().x - x), 2.0f) + powf((sprite.getPosition().y - y), 2.0f));

}

float projectile::getHitbox() {
    return hitboxRadius;

}

int projectile::getDamage() {
    return damage;

}

void projectile::move() {
    sprite.setPosition(sprite.getPosition().x + vel[0], sprite.getPosition().y + vel[1]);
    
}

void projectile::setEnemy(bool unfriendly) {
    enemy = unfriendly;
    if(enemy) {
        sprite.setRotation(180);
        setVel_y(shootSpeed);

    }
    else {
        sprite.setRotation(0);
        setVel_y(-1.0f * shootSpeed);

    }

}

bool projectile::getEnemy() {
    return enemy;

}