#ifndef BALL_H
#define BALL_H

#include "raylib.h"

class Ball
{
public:
    Ball(Vector2 pos);
    virtual void tick(float deltaTime);
    void restart(); //restart the ball to original state when a new game is started
    void reset(); //reset the ball to original position with reverse velocity when new round is started
    
    Vector2 getCurrentPos() {return currentPos;};
    int getRadius() {return radius;};
    Vector2 getVelocity() {return velocity;};

    void setVelocity(Vector2 newVelocity) {velocity = newVelocity;};
    void setPosition(Vector2 pos) {currentPos = pos;};

protected:
    Vector2 startPos{}, currentPos{};
    int radius{20};
    Vector2 velocity{5,0};
};

#endif