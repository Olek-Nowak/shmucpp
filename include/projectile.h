#ifndef PROJECTILE
#define PROJECTILE
#include "string"
#include "IPhysics.h"
#include "IDrawable.h"

class projectile : IPhysics, IDrawable {
private:
    int damage;
    float shootSpeed;
    float pos[2];
    float vel[2];
    float hitboxRadius;
    float boundries[2];
    sf::Texture texture;
public:
    bool visible;
    sf::Sprite sprite;
    projectile(std::string res);
    void setVel_x(float vx);
    void setVel_y(float vy);
    void setPos_x(float px);
    void setPos_y(float py);
    float getDist(float x, float y);
    float getHitbox();
    void move();

};

#endif