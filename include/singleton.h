#ifndef SINGLETON
#define SINGLETON

class Singleton {
protected:
    Singleton();
public:
    static Singleton& getInstance();

};

#endif