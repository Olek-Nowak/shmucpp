#ifndef IPHYSICS
#define IPHYSICS

class IPhysics {
protected:
    float vel[2];
    float hitboxRadius;
    float boundries[2];
public:
    virtual void setVel_x(float vx) = 0;
    virtual void setVel_y(float vy) = 0;
    virtual float getHitbox() = 0;
    virtual bool update(int ms) = 0;

};

#endif