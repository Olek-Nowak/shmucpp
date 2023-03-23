#ifndef ENTITY
#define ENTITY
#include "string"
#include "IPhysics.h"
#include "IDamageable.h"
#include "IDrawable.h"
#include "weapon.h"

class entity : IPhysics, IDamageable, IDrawable {
private:
    int maxHealth;
    int health;
    float vel[2];
    float pos[2];
    float hitboxRadius;
    float boundries[2];
    sf::Texture texture;
public:
    weapon* wep = nullptr;
    sf::Sprite sprite;
    entity(int hp, float startx, float starty, float hitbox, float boundryx, float boundryy, std::string res, weapon w);
    void onHit(int damage);
    void setVel_x(float vx);
    void setVel_y(float vy);
    float getDist(float x, float y);
    float getHitbox();
    void move();
    void destroy();

};

#endif