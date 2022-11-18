#include "Ball.h"
#include "raymath.h"

Ball::Ball()
{
}

void Ball::setStartPos(Vector2 pos)
{
    startPos = pos;
    currentPos = pos;
}

void Ball::tick(float deltaTime)
{
    currentPos = Vector2Add(currentPos, velocity);
    
    DrawCircle(currentPos.x, currentPos.y, radius, WHITE);
}

void Ball::restart()
{
    currentPos = startPos;
    velocity = Vector2{5,0};
}

void Ball::reset()
{
    velocity.x = -velocity.x;
    currentPos = startPos;
}