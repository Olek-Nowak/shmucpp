#ifndef POOL
#define POOL
#include "projectile.h"
#include <vector>

class pool {
protected:
    std::vector<projectile*> bullets;
    int num;
public:
    projectile getNew();
    pool(int buffer, std::string res);
    ~pool();

};

#endif