#ifndef SCENE_AI
#define SCENE_AI

#include "Base_Scene.h"
#include "Ball.h"
#include "Paddle_Player.h"
#include "Paddle_AI.h"

class Scene_AI : public Base_Scene
{
public:
    Scene_AI(int winWidth, int winHeight);
    virtual int tick(float deltaTime) override;
    virtual void Reset() override;

    void SetDifficulty(int difficulty);

protected:
    bool shouldResetBall{false};

    //Ball set up
    Ball ball{};

    //Paddle Set Up
    Paddle_Player playerPaddle{KEY_W, KEY_S};
    Paddle_AI AIPaddle{1};

    float instructionsDisplayTimer{3.0f};
};

#endif