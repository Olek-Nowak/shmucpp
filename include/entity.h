#ifndef ENTITY
#define ENTITY
#include "IPhysics.h"
#include "IDrawable.h"

class entity : IPhysics, IDrawable {
protected:
    float vel[2];
    float hitboxRadius;
    float boundries[2];
    bool disabled;
public:
    sf::Sprite sprite;
    entity();
    virtual ~entity();
    void setVel_x(float vx);
    void setVel_y(float vy);
    virtual bool checkCollision(entity e);
    float getHitbox();
    virtual bool update(int msElapsed);
    bool getDisabled();
    void setDisabled(bool d);

};

#endif