#ifndef PVP_INTERFACE
#define PVP_INTERFACE

#include "Base_Interface.h"
#include "Ball.h"
#include "Paddle.h"

class PVP_Interface : public Base_Interface
{
public:
    PVP_Interface(int winWidth, int winHeight);
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