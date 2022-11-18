#ifndef BASE_INTERFACE
#define BASE_INTERFACE

#include "raylib.h"

class Base_Interface
{
public:
    Base_Interface();
    virtual int tick(float deltaTime);
    virtual void Reset();

protected:
    int width{}, height{};
    int GUI_ID{}, GUI_Selection{};
};

#endif