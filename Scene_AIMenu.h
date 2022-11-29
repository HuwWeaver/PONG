#ifndef SCENE_AIMENU
#define SCENE_AIMENU

#include "Base_Scene.h"

class Scene_AIMenu : public Base_Scene
{
public:
    Scene_AIMenu(int winWidth, int winHeight);
    virtual int tick(float deltaTime) override;
    virtual void Reset() override;

private:
    Vector2 circlePos{};
    int menuSelection{0};
    float inputBuffer{0.2f};

};

#endif