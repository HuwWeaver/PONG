#ifndef SCENE_MAINMENU
#define SCENE_MAINMENU

#include "Base_Scene.h"

class Scene_MainMenu : public Base_Scene
{
public:
    Scene_MainMenu(int winWidth, int winHeight);
    virtual int tick(float deltaTime) override;
    virtual void Reset() override;

private:
    Vector2 circlePos{};
    int menuSelection{0};
    float inputBuffer{0.0f};

};

#endif