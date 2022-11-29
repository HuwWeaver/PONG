#ifndef BASE_SCENE
#define BASE_SCENE

#include "raylib.h"

class Base_Scene
{
public:
    Base_Scene();
    virtual int tick(float deltaTime);
    virtual void Reset();

protected:
    int width{}, height{};
    int sceneID{}, sceneSelection{};
};

#endif