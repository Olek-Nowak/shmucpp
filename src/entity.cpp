#include "entity.h"
#include "cmath"
using namespace std;

entity::entity(int hp, float startx, float starty, float hitbox, float boundryx, float boundryy, string res, weapon w) {
    pos[0] = startx;
    pos[1] = starty;
    maxHealth = hp;
    health = maxHealth;
    hitboxRadius = hitbox;
    boundries[0] = boundryx;
    boundries[1] = boundryy;
    vel[0] = 0.0f;
    vel[1] = 0.0f;
    wep = new weapon(w);
    texture.loadFromFile(res);
    sprite = sf::Sprite(texture);
    sprite.setPosition(startx, starty);

}

void entity::onHit(int damage) {
    health -= damage;
    if(health <= 0)
        destroy();

}

void entity::setVel_x(float vx) {
    vel[0] = vx;

}

void entity::setVel_y(float vy) {
    vel[1] = vy;

}

float entity::getDist(float x, float y) {
    return sqrtf(powf((pos[0] - x), 2.0f) + powf((this->pos[1] - y), 2.0f));

}

float entity::getHitbox() {
    return hitboxRadius;

}

void entity::move() {
    pos[0] += vel[0];
    pos[1] += vel[1];
    /*if(pos[0] > boundries[0])
        pos[0] = boundries[0];
    if(pos[1] > boundries[1])
        pos[1] = boundries[1];*/
    sprite.setPosition(pos[0], pos[1]);

}

void entity::destroy() {


}