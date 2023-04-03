#include "projectile.h"
using namespace std;

// TODO: collision detection

projectile::projectile(string res) {
    visible = 0;
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


}

float projectile::getHitbox() {


}

void projectile::move() {
    sprite.setPosition(sprite.getPosition().x + vel[0], sprite.getPosition().y + vel[1]);
    
}