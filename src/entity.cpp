#include "entity.h"
#include "cmath"
using namespace std;

// TODO: boundries

entity::entity(int hp, float startx, float starty, float hitbox, float boundryx, float boundryy, string res, weapon w) {
    disabled = 0;
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
    // SFML standard sprite position is counted from top left corner, need to reset origin point
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setPosition(startx, starty);

}

void entity::onHit(int damage) {
    health -= damage;
    if(health <= 0)
        disabled = 1;

}

void entity::setVel_x(float vx) {
    vel[0] = vx;

}

void entity::setVel_y(float vy) {
    vel[1] = vy;

}

float entity::getDist(float x, float y) {
    return sqrtf(powf((sprite.getPosition().x - x), 2.0f) + powf((sprite.getPosition().y - y), 2.0f));

}

float entity::getHitbox() {
    return hitboxRadius;

}

void entity::move() {
    /*if(pos[0] > boundries[0])
        pos[0] = boundries[0];
    if(pos[1] > boundries[1])
        pos[1] = boundries[1];*/
    sprite.setPosition(sprite.getPosition().x + vel[0], sprite.getPosition().y + vel[1]);
}

void entity::destroy() {


}

entity::~entity() {
    delete wep;

}