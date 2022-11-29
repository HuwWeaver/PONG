#ifndef PADDLE_H
#define PADDLE_H

#include "Base_Paddle.h"

class Paddle_Player : public Base_Paddle
{
public:
    Paddle_Player(KeyboardKey up, KeyboardKey down);
    virtual void tick(float deltaTime) override;

protected:
    KeyboardKey upKey{}, downKey{};

};

#endif