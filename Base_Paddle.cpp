#include "Base_Paddle.h"

Base_Paddle::Base_Paddle()
{
}

void Base_Paddle::restart()
{
    currentPos = startPos;
    score = 0;
}

void Base_Paddle::setStartPos(int windowWidth, int windowHeight, bool leftPaddle)
{
    winWidth = windowWidth;
    winHeight = windowHeight;
    
    if(leftPaddle)
    {
        startPos = Vector2{50.0f, static_cast<float>((winHeight/2) - (height/2))};
    }
    else
    {
        startPos = Vector2{winWidth - width - 50.0f, static_cast<float>((winHeight/2) - (height/2))};
    }
    
    currentPos = startPos;
}

Rectangle Base_Paddle::GetCollisionRect()
{
    return {
        currentPos.x,
        currentPos.y,
        static_cast<float>(width),
        static_cast<float>(height)
    };
}

void Base_Paddle::tick(float deltaTime)
{
}