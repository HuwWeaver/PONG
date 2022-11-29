#include "Paddle_Player.h"

Paddle_Player::Paddle_Player(KeyboardKey up, KeyboardKey down) : upKey(up), downKey(down)
{
}

void Paddle_Player::tick(float deltaTime)
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