#include "Scene_PVP.h"
#include "raylib.h"
#include <iostream>

Scene_PVP::Scene_PVP(int winWidth, int winHeight)
{
    Scene_ID = 1;
    Scene_Selection = Scene_ID;

    width = winWidth;
    height = winHeight;

    ball.setStartPos(Vector2{static_cast<float>(width) / 2.0f, static_cast<float>(height) / 2.0f});
    ball.setWinHeightRef(height);

    leftPaddle.setStartPos(width, height, true);
    rightPaddle.setStartPos(width, height, false);
}

int Scene_PVP::tick(float deltaTime)
{
    if (leftPaddle.GetScore() >= 3 || rightPaddle.GetScore() >= 3)
    {
        if (leftPaddle.GetScore() >= 3)
        {
            DrawText("Left Player Wins!", width / 2 - 100, height / 2, 30, WHITE);
        }
        else
        {
            DrawText("Right Player Wins!", width / 2 - 100, height / 2, 30, WHITE);
        }

        // When moving Game Over text into its own scene, move from here -------
        DrawText("Game Over!", width / 2 - 100, height / 2 - 50, 50, RED);
        DrawText("Press R to Restart", width / 2 - 100, height / 2 + 35, 20, BLUE);
        DrawText("or M to Return to Menu", width / 2 - 100, height / 2 + 55, 20, BLUE);

        if (IsKeyDown(KEY_R)) // Reset PVP game on R key press
        {
            Reset();
            Scene_Selection = 1; //Play PVP
        }

        if (IsKeyDown(KEY_M))
        {
            Scene_Selection = 0; //Return to Menu
        }

        return Scene_Selection;
        // to here -------------------------------------------------------------

        // Scene_Selection = 99;
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
        std::string temp_score = std::to_string(leftPaddle.GetScore()) + " : " + std::to_string(rightPaddle.GetScore());
        DrawText(temp_score.c_str(), width / 2 - 40, 25, 50, WHITE);

        // If ball collision with paddle, move away from paddle and reverse direction
        if (CheckCollisionCircleRec(ball.getCurrentPos(), ball.getRadius(), rightPaddle.GetCollisionRect()))
        {
            // Right Paddle
            ball.hitPaddle(rightPaddle, false);
        }
        if (CheckCollisionCircleRec(ball.getCurrentPos(), ball.getRadius(), leftPaddle.GetCollisionRect()))
        {
            // Left Player
            ball.hitPaddle(leftPaddle, true);
        }

        // If ball reaches left/right edge of screen, give score and reset
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

        // Paddle Update
        leftPaddle.tick(deltaTime);
        rightPaddle.tick(deltaTime);

        // Game Logic Ends
    }

    return Scene_Selection;
}

void Scene_PVP::Reset()
{
    ball.restart();
    leftPaddle.restart();
    rightPaddle.restart();
    Scene_Selection = Scene_ID;
}