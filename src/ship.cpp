#include <cmath>
#include "ship.h"
using namespace std;

// TODO: boundries

ship::ship(int hp, float startx, float starty, float hitbox, sf::Texture &res, int weaponCD) {
    disabled = 0;
    maxHealth = hp;
    health = maxHealth;
    hitboxRadius = hitbox;
    //boundries[0] = boundryx;
    //boundries[1] = boundryy;
    vel[0] = 0.0f;
    vel[1] = 0.0f;
    maxCD = weaponCD;
    cooldown = maxCD;
    sprite = sf::Sprite(res);
    // SFML standard sprite position is counted from top left corner, need to reset origin point
    sprite.setOrigin(res.getSize().x / 2, res.getSize().y / 2);
    sprite.setPosition(startx, starty);

}

ship::~ship() {

}

bool ship::checkCollision(entity* e) {
    // prevents already disabled (marked for delete) but not yet deleted projectiles
    if(e->getDisabled() && e->getHitbox() < 6.0f)
        return false;
    float dist = sqrtf(powf((sprite.getPosition().x - e->sprite.getPosition().x), 2.0f) + powf((sprite.getPosition().y - e->sprite.getPosition().y), 2.0f));
    if(dist <= hitboxRadius + e->getHitbox()) {
        onHit(1);
        return true;

    }
    else return false;

}

void ship::onHit(int damage) {
    health -= damage;
    if(health <= 0)
        disabled = 1;

}

void ship::destroy() {
// reserved for anims

}

bool ship::update(int msElapsed) {
    /*if(pos[0] > boundries[0])
        pos[0] = boundries[0];
    if(pos[1] > boundries[1])
        pos[1] = boundries[1];*/
    sprite.setPosition(vel[0] + sprite.getPosition().x, vel[1] + sprite.getPosition().y);
    if(maxCD <= 0)
        return 0;
    cooldown -= msElapsed;
    if(cooldown <= 0) {
        cooldown = maxCD;
        return 1;

    }
    else return 0;

}