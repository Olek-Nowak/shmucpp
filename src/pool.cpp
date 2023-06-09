#include "pool.h"
using namespace std;

projectile pool::getNew() {
    for(int i = 0; i < num; i++) {
        if(bullets[i]->getDisabled()) {
            bullets[i]->setDisabled(false);
            return *(bullets[i]);

        }

    }

}

pool::pool(int buffer, sf::Texture &res) {
    num = buffer;
    bullets.resize(num);
    for(int i = 0; i < num; i++) {
        bullets[i] = new projectile(res);
        
    }

}

pool::~pool() {
    for(int i = 0; i < num; i++) {
        delete bullets[i];
        
    }
    bullets.clear();

}