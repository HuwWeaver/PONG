#include <iostream>
#include "raylib.h"
#include "Ball.h"
#include "Paddle.h"

int main()
{
    //Window Dimensions
    int width{1000};
    int height{650};
    InitWindow(width, height, "PONG!");

    //Ball set up
    Ball ball{Vector2{static_cast<float>(width) / 2.0f, static_cast<float>(height) / 2.0f}};

    //Paddle Set Up
    Paddle leftPaddle{KEY_W, KEY_S};
    leftPaddle.setStartPos(width, height, true);
    Paddle rightPaddle{KEY_UP, KEY_DOWN};
    rightPaddle.setStartPos(width, height, false);

    bool shouldReset{false};

    SetTargetFPS(120);

    while (!WindowShouldClose())
    {
        // Delta time
        float dt = GetFrameTime();

        BeginDrawing();
        ClearBackground(BLACK);

        if (leftPaddle.GetScore() >= 3 || rightPaddle.GetScore() >= 3)
        {
            DrawText("Game Over!", width/2 - 100, height/2 - 50 , 50, RED);
            if(leftPaddle.GetScore() >= 3)
            {
                DrawText("Left Player Wins!", width/2 - 100, height/2, 30, WHITE);
            }
            else
            {
                DrawText("Right Player Wins!", width/2 - 100, height/2, 30, WHITE);
            }
            DrawText("Press R to Restart", width/2 - 100, height/2 + 35, 20, BLUE);

            if(IsKeyDown(KEY_R)) //Restart game on R key press
            {
                ball.restart();
                leftPaddle.restart();
                rightPaddle.restart();
            }
        }
        else
        {
            //Game Logic Begins
            if(shouldReset)
            {
                ball.reset();
                shouldReset = false;
            }

            //Update Ball
            ball.tick(dt);

            //Display Score
            std::string temp_lp_score = std::to_string(leftPaddle.GetScore());
            std::string temp_rp_score = std::to_string(rightPaddle.GetScore());
            std::string temp_score = temp_lp_score + " : " + temp_rp_score;
            char const* final_score = temp_score.c_str();
            DrawText(final_score, width/2 - 40, 25, 50, WHITE);

            //If ball collision with player, move away from player and reverse direction
            //Right Player
            if(CheckCollisionCircleRec(ball.getCurrentPos(), ball.getRadius(), rightPaddle.GetCollisionRect()))
            {
                ball.setVelocity(Vector2{-ball.getVelocity().x, (ball.getCurrentPos().y - (rightPaddle.GetCurrentPos().y + (rightPaddle.GetHeight() / 2))) / 10});
                ball.setPosition(Vector2{rightPaddle.GetCurrentPos().x - ball.getRadius(), ball.getCurrentPos().y});
            }
            //Left Player
            if(CheckCollisionCircleRec(ball.getCurrentPos(), ball.getRadius(), leftPaddle.GetCollisionRect()))
            {
                ball.setVelocity(Vector2{-ball.getVelocity().x, (ball.getCurrentPos().y - (leftPaddle.GetCurrentPos().y + (leftPaddle.GetHeight() / 2))) / 10});
                ball.setPosition(Vector2{leftPaddle.GetCurrentPos().x + leftPaddle.GetWidth() + ball.getRadius(), ball.getCurrentPos().y});
            }

            //If circle reaches left/right edge of screen, give score and reset
            if(ball.getCurrentPos().x < 0)
            {
                rightPaddle.setScore(rightPaddle.GetScore() + 1);
                shouldReset = true;
            }
            if(ball.getCurrentPos().x > width)
            {
                leftPaddle.setScore(leftPaddle.GetScore() + 1);
                shouldReset = true;
            }

            //If circle reaches top/bottom edge of screen, reverse y direction
            if(ball.getCurrentPos().y < 0 || ball.getCurrentPos().y > height)
            {
                ball.setVelocity(Vector2{ball.getVelocity().x, -ball.getVelocity().y});
            }

            //Player Input
            leftPaddle.tick(dt);
            rightPaddle.tick(dt);

            //Game Logic Ends
        }

        EndDrawing();
    }

    CloseWindow();
}