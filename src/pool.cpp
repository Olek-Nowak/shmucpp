#include "pool.h"
using namespace std;

projectile* pool::getNew() {
    for(int i = 0; i < num; i++) {
        if(bullets[i]->getDisabled()) {
            bullets[i]->setDisabled(false);
            bullets[i]->sprite.setRotation(0);
            bullets[i]->setVel_x(0.0f);
            bullets[i]->setVel_y(0.0f);
            return bullets[i];

        }

    }

}

pool::pool(int buffer, sf::Texture &res) {
    num = buffer;
    bullets.resize(num);
    for(int i = 0; i < num; i++) {
        bullets[i] = new projectile(res);
        bullets[i]->setDisabled(true);
        
    }

}

pool::~pool() {
    for(int i = 0; i < num; i++) {
        delete bullets[i];
        
    }
    bullets.clear();

}