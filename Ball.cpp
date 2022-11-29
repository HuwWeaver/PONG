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

    // If ball reaches top/bottom edge of screen, reverse y direction
    if (getCurrentPos().y < 0 || getCurrentPos().y > windowHeight)
    {
        setVelocity(Vector2{getVelocity().x, -getVelocity().y});
    }

    DrawCircle(currentPos.x, currentPos.y, radius, WHITE);
}

void Ball::restart()
{
    currentPos = startPos;
    velocity = Vector2{5, 0};
}

void Ball::reset()
{
    velocity.x = -velocity.x;
    currentPos = startPos;
}

void Ball::hitPaddle(Base_Paddle paddle, bool isLeftPaddle)
{
    float paddleMidpoint = paddle.GetCurrentPos().y + (paddle.GetHeight() / 2);

    // Reverse X velocity, set Y to distance between ball Y pos and paddle midpoint / 10 (therefore scales result Y velocity depending on where hit paddle)
    setVelocity(Vector2{-getVelocity().x, (getCurrentPos().y - paddleMidpoint) / 10});

    // Move ball to front of paddle incase it hit edge (stops it getting stuck in collision loop)
    if (isLeftPaddle)
    {
        setPosition(Vector2{paddle.GetCurrentPos().x + paddle.GetWidth() + getRadius(), getCurrentPos().y});
    }
    else
    {
        setPosition(Vector2{paddle.GetCurrentPos().x - getRadius(), getCurrentPos().y});
    }
}