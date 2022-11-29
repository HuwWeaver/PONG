#ifndef BASE_PADDLE_H
#define BASE_PADDLE_H

#include "raylib.h"

class Base_Paddle
{
public:
    Base_Paddle();
    void restart();
    virtual void tick(float deltaTime);

    Rectangle GetCollisionRect();
    Vector2 GetCurrentPos() {return currentPos;};
    int GetWidth() {return width;};
    int GetHeight() {return height;};
    int GetScore() {return score;};

    void setStartPos(int windowWidth, int windowHeight, bool leftPaddle);
    void setScore(int newScore) {score = newScore;};

protected:
    int width{25};
    int height{100};
    Vector2 startPos{}, currentPos{};
    KeyboardKey upKey{}, downKey{};
    int winWidth{}, winHeight{};
    int score{0};
};

#endif