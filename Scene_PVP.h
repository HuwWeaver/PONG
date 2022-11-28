#ifndef SCENE_PVP
#define SCENE_PVP

#include "Base_Scene.h"
#include "Ball.h"
#include "Paddle.h"

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
    Paddle leftPaddle{KEY_W, KEY_S};
    Paddle rightPaddle{KEY_UP, KEY_DOWN};
};

#endif