#ifndef PROJECTILE
#define PROJECTILE
#include "IPhysics.h"
#include "IDrawable.h"

class projectile : IPhysics, IDrawable {
private:
    int damage;
    float shootSpeed;
    float vel[2];
    float hitboxRadius;
    float boundries[2];
public:
    bool disabled;
    sf::Sprite sprite;
    projectile(sf::Texture &res);
    void setVel_x(float vx);
    void setVel_y(float vy);
    float getDist(float x, float y);
    float getHitbox();
    int getDamage();
    void move();

};

#endif