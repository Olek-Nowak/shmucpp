#include "projectile.h"
using namespace std;

projectile::projectile(string res) {
    visible = 0;
    hitboxRadius = 5;
    damage = 1;
    shootSpeed = 0;
    pos[0] = 0;
    pos[1] = 0;
    texture.loadFromFile(res);
    sprite = sf::Sprite(texture);
    sprite.setPosition(0, 0);
    sprite.scale(0.5f, 0.5f);
    setVel_x(0.0f);
    setVel_y(0.0f);

}

void projectile::setVel_x(float vx) {
    vel[0] = vx;

}

void projectile::setVel_y(float vy) {
    vel[1] = vy;

}

void projectile::setPos_x(float px) {
    pos[0] = px;

}

void projectile::setPos_y(float py) {
    pos[1] = py;

}

float projectile::getDist(float x, float y) {


}

float projectile::getHitbox() {


}

void projectile::move() {
    pos[0] += vel[0];
    pos[1] += vel[1];
    sprite.setPosition(pos[0], pos[1]);
    
}