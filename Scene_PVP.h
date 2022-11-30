#ifndef SCENE_PVP
#define SCENE_PVP

#include "Base_Scene.h"
#include "Ball.h"
#include "Paddle_Player.h"

class Scene_PVP : public Base_Scene
{
public:
    Scene_PVP(int winWidth, int winHeight);
    virtual int tick(float deltaTime) override;
    virtual void Reset() override;

protected:
    bool shouldResetBall{false};

    //Ball set up
    Ball ball{};

    //Paddle Set Up
    Paddle_Player leftPaddle{KEY_W, KEY_S};
    Paddle_Player rightPaddle{KEY_UP, KEY_DOWN};

    float instructionsDisplayTimer{3.0f};
};

#endif