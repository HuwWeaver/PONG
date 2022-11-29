#ifndef PADDLE_AI_H
#define PADDLE_AI_H

#include "Base_Paddle.h"
#include "raymath.h"
#include "Ball.h"

class Paddle_AI : public Base_Paddle
{
public:
    Paddle_AI(int difficultyLvl);
    virtual void tick(float deltaTime, Ball ball);

    void SetDifficulty(int newDifficulty) {difficulty = newDifficulty;};

protected:
    int difficulty{};
    Color getPaddleColour(int difficulty);
};

#endif