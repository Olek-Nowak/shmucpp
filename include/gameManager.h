#ifndef GAME
#define GAME
#include "singleton.h"

class gameManager : Singleton {
private:
    gameManager();
public:
    ~gameManager();
    static gameManager& getInstance();
    void input_left();
    void input_right();
    void pause();

};



#endif