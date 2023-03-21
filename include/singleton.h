#ifndef SINGLETON
#define SINGLETON

class singleton {
protected:
    singleton();
public:
    static singleton& getInstance();

};

#endif