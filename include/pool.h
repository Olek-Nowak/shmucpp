#ifndef POOL
#define POOL
#include <string>
#include "projectile.h"
#include <vector>

class pool {
protected:
    std::vector<projectile*> bullets;
    int num;
public:
    projectile getNew();
    pool(int buffer, sf::Texture &res);
    ~pool();

};

#endif