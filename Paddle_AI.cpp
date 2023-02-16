#include "Paddle_AI.h"

Paddle_AI::Paddle_AI(int difficultyLvl) : difficulty(difficultyLvl)
{
}

void Paddle_AI::tick(float deltaTime, Ball ball)
{
    currentPos.y = Lerp(currentPos.y, (ball.getCurrentPos().y - (height/2)), difficulty * 0.025f);

    if(currentPos.y < 0) currentPos.y = 0;
    if(currentPos.y > winHeight - height) currentPos.y = winHeight - height;

    DrawRectangle(currentPos.x, currentPos.y, width, height, difficultyColour[difficulty]);
}