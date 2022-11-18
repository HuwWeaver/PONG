#include "PVP_Interface.h"
#include "raylib.h"
#include <iostream>

PVP_Interface::PVP_Interface(int winWidth, int winHeight)
{
    GUI_ID = 1;
    GUI_Selection = GUI_ID;
    
    width = winWidth;
    height = winHeight;

    ball.setStartPos(Vector2{static_cast<float>(width) / 2.0f, static_cast<float>(height) / 2.0f});

    leftPaddle.setStartPos(width, height, true);
    rightPaddle.setStartPos(width, height, false);
}

int PVP_Interface::tick(float deltaTime)
{
    if (leftPaddle.GetScore() >= 3 || rightPaddle.GetScore() >= 3)
    {
        /* 
        if (leftPaddle.GetScore() >= 3)
        {
            DrawText("Left Player Wins!", width / 2 - 100, height / 2, 30, WHITE);
        }
        else
        {
            DrawText("Right Player Wins!", width / 2 - 100, height / 2, 30, WHITE);
        }
        */

       GUI_Selection = 99;
    }
    else
    {
        // Game Logic Begins
        if (shouldResetBall)
        {
            ball.reset();
            shouldResetBall = false;
        }

        // Update Ball
        ball.tick(deltaTime);

        // Display Score
        std::string temp_lp_score = std::to_string(leftPaddle.GetScore());
        std::string temp_rp_score = std::to_string(rightPaddle.GetScore());
        std::string temp_score = temp_lp_score + " : " + temp_rp_score;
        char const *final_score = temp_score.c_str();
        DrawText(final_score, width / 2 - 40, 25, 50, WHITE);

        // If ball collision with player, move away from player and reverse direction
        // Right Player
        if (CheckCollisionCircleRec(ball.getCurrentPos(), ball.getRadius(), rightPaddle.GetCollisionRect()))
        {
            ball.setVelocity(Vector2{-ball.getVelocity().x, (ball.getCurrentPos().y - (rightPaddle.GetCurrentPos().y + (rightPaddle.GetHeight() / 2))) / 10});
            ball.setPosition(Vector2{rightPaddle.GetCurrentPos().x - ball.getRadius(), ball.getCurrentPos().y});
        }
        // Left Player
        if (CheckCollisionCircleRec(ball.getCurrentPos(), ball.getRadius(), leftPaddle.GetCollisionRect()))
        {
            ball.setVelocity(Vector2{-ball.getVelocity().x, (ball.getCurrentPos().y - (leftPaddle.GetCurrentPos().y + (leftPaddle.GetHeight() / 2))) / 10});
            ball.setPosition(Vector2{leftPaddle.GetCurrentPos().x + leftPaddle.GetWidth() + ball.getRadius(), ball.getCurrentPos().y});
        }

        // If circle reaches left/right edge of screen, give score and reset
        if (ball.getCurrentPos().x < 0)
        {
            rightPaddle.setScore(rightPaddle.GetScore() + 1);
            shouldResetBall = true;
        }
        if (ball.getCurrentPos().x > width)
        {
            leftPaddle.setScore(leftPaddle.GetScore() + 1);
            shouldResetBall = true;
        }

        // If circle reaches top/bottom edge of screen, reverse y direction
        if (ball.getCurrentPos().y < 0 || ball.getCurrentPos().y > height)
        {
            ball.setVelocity(Vector2{ball.getVelocity().x, -ball.getVelocity().y});
        }

        // Player Input
        leftPaddle.tick(deltaTime);
        rightPaddle.tick(deltaTime);

        // Game Logic Ends
    }

    return GUI_Selection;
}

void PVP_Interface::Reset()
{
    ball.restart();
    leftPaddle.restart();
    rightPaddle.restart();
    GUI_Selection = GUI_ID;
}