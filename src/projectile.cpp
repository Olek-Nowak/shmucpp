#include "projectile.h"
using namespace std;

projectile::projectile(int dmg, float spd, float startx, float starty, float hitbox, string res) {
    hitboxRadius = hitbox;
    damage = dmg;
    shootSpeed = spd;
    pos[0] = startx;
    pos[1] = starty;
    texture.loadFromFile(res);
    sprite = sf::Sprite(texture);
    sprite.setPosition(startx, starty);
    sprite.scale(0.5f, 0.5f);
    setVel_x(0.0f);
    setVel_y(shootSpeed);

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
    pos[0] += vel[0];
    pos[1] += vel[1];
    sprite.setPosition(pos[0], pos[1]);
    
}