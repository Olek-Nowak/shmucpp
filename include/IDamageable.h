#ifndef DAMAGE
#define DAMAGE

class IDamageable {
protected:
    int maxHealth;
    int health;
public:
    virtual void onHit(int damage) = 0;
    virtual void destroy() = 0;

};

#endif