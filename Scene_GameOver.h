#ifndef SCENE_GAMEOVER
#define SCENE_GAMEOVER

#include "Base_Scene.h"

class Scene_GameOver : public Base_Scene
{
public:
    Scene_GameOver(int winWidth, int winHeight);
    virtual int tick(float deltaTime) override;
    virtual void Reset() override;
};

#endif