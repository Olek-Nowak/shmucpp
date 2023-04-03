#include "pool.h"
#include "entity.h"
#include "projectile.h"
using namespace std;

projectile pool::getNew() {
    for(int i = 0; i < num; i++) {
        if(bullets[i]->disabled) {
            bullets[i]->disabled = 0;
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