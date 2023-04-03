#include <cmath>
#include "projectile.h"
using namespace std;

projectile::projectile(string res) {
    disabled = 0;
    hitboxRadius = 5.0f;
    damage = 1;
    shootSpeed = 3.0f;
    texture.loadFromFile(res);
    sprite = sf::Sprite(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.scale(0.5f, 0.5f);
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