#include "Scene_AI.h"
#include "raylib.h"
#include <iostream>

Scene_AI::Scene_AI(int winWidth, int winHeight)
{
    sceneID = 20;
    sceneSelection = sceneID;

    width = winWidth;
    height = winHeight;

    ball.setStartPos(Vector2{static_cast<float>(width) / 2.0f, static_cast<float>(height) / 2.0f});
    ball.setWinHeightRef(height);

    playerPaddle.setStartPos(width, height, true);
    AIPaddle.setStartPos(width, height, false);
}

int Scene_AI::tick(float deltaTime)
{
    if (playerPaddle.GetScore() >= 3 || AIPaddle.GetScore() >= 3)
    {
        if (playerPaddle.GetScore() >= 3)
        {
            DrawText("Left Player Wins!", width / 2 - 100, height / 2, 30, WHITE);
        }
        else
        {
            DrawText("AI Wins!", width / 2 - 100, height / 2, 30, WHITE);
        }

        // When moving Game Over text into its own scene, move from here -------
        DrawText("Game Over!", width / 2 - 100, height / 2 - 50, 50, RED);
        DrawText("Press R to Restart", width / 2 - 100, height / 2 + 35, 20, BLUE);
        DrawText("or M to Return to Menu", width / 2 - 100, height / 2 + 55, 20, BLUE);

        if (IsKeyDown(KEY_R)) // Reset AI game on R key press
        {
            Reset();
            sceneSelection = sceneID; //Play AI
        }

        if (IsKeyDown(KEY_M))
        {
            sceneSelection = 0; //Return to Menu
        }

        return sceneSelection;
        // to here -------------------------------------------------------------

        // sceneSelection = 99;
    }
    else
    {
        // Game Logic Begins
        if (shouldResetBall)
        {
            ball.reset();
            shouldResetBall = false;
        }

        //Show instructions if timer not 0
        if(instructionsDisplayTimer > 0)
        {
            instructionsDisplayTimer -= deltaTime;
            DrawText("W/S to move paddle", width/10, height/2 + 50, 25, WHITE);
        }

        // Update Ball
        ball.tick(deltaTime);

        // Display Score
        std::string temp_score = std::to_string(playerPaddle.GetScore()) + " : " + std::to_string(AIPaddle.GetScore());
        DrawText(temp_score.c_str(), width / 2 - 40, 25, 50, WHITE);

        // If ball collision with paddle, move away from paddle and reverse direction
        if (CheckCollisionCircleRec(ball.getCurrentPos(), ball.getRadius(), AIPaddle.GetCollisionRect()))
        {
            // Right Paddle
            ball.hitPaddle(AIPaddle, false);
        }
        if (CheckCollisionCircleRec(ball.getCurrentPos(), ball.getRadius(), playerPaddle.GetCollisionRect()))
        {
            // Left Player
            ball.hitPaddle(playerPaddle, true);
        }

        // If ball reaches left/right edge of screen, give score and reset
        if (ball.getCurrentPos().x < 0)
        {
            AIPaddle.setScore(AIPaddle.GetScore() + 1);
            shouldResetBall = true;
        }
        if (ball.getCurrentPos().x > width)
        {
            playerPaddle.setScore(playerPaddle.GetScore() + 1);
            shouldResetBall = true;
        }

        // Paddle Update
        playerPaddle.tick(deltaTime);
        AIPaddle.tick(deltaTime, ball);

        // Game Logic Ends
    }

    return sceneSelection;
}

void Scene_AI::Reset()
{
    ball.restart();
    playerPaddle.restart();
    AIPaddle.restart();
    sceneSelection = sceneID;
    instructionsDisplayTimer = 3.0f;
}

void Scene_AI::SetDifficulty(int difficulty)
{
    AIPaddle.SetDifficulty(difficulty);
}