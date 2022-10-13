#include "Paddle.h"

Paddle::Paddle(KeyboardKey up, KeyboardKey down) : upKey(up), downKey(down)
{
}

void Paddle::restart()
{
    currentPos = startPos;
    score = 0;
}

void Paddle::setStartPos(int windowWidth, int windowHeight, bool leftPlayer)
{
    winWidth = windowWidth;
    winHeight = windowHeight;
    
    if(leftPlayer)
    {
        startPos = Vector2{50.0f, static_cast<float>((winHeight/2) - (height/2))};
    }
    else
    {
        startPos = Vector2{winWidth - width - 50.0f, static_cast<float>((winHeight/2) - (height/2))};
    }
    
    currentPos = startPos;
}

Rectangle Paddle::GetCollisionRect()
{
    return {
        currentPos.x,
        currentPos.y,
        static_cast<float>(width),
        static_cast<float>(height)
    };
}

void Paddle::tick(float deltaTime)
{
    if ((IsKeyDown(downKey)) && currentPos.y < winHeight - height)
    {
        currentPos.y += 10;
    }

    if ((IsKeyDown(upKey)) && currentPos.y > 0)
    {
        currentPos.y -= 10;
    }

    DrawRectangle(currentPos.x, currentPos.y, width, height, WHITE);
}