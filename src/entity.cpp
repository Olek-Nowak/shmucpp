#include "entity.h"
#include "cmath"
using namespace std;

// TODO: boundries

entity::entity() {
    
}

entity::~entity() {
    
}

void entity::setVel_x(float vx) {
    vel[0] = vx;

}

void entity::setVel_y(float vy) {
    vel[1] = vy;

}

bool entity::checkCollision(entity e) {
    return false;
}

float entity::getHitbox() {
    return hitboxRadius;

}

bool entity::update(int msElapsed) {
    return false;
}

bool entity::getDisabled() {
    return disabled;

}

void entity::setDisabled(bool d) {
    disabled = d;

}