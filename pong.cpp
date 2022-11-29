#include <iostream>
#include "raylib.h"
#include "Scene_MainMenu.h"
#include "Scene_PVP.h"
#include "Scene_GameOver.h"
#include "Scene_AI.h"
#include "Scene_AIMenu.h"

int main()
{
    // Window Dimensions
    int width{1280};
    int height{720};
    InitWindow(width, height, "PONG!");

    int targetScene{0};
    int currentScene{0};
    bool quitGame{false};

    Scene_MainMenu MainMenu(width, height);
    Scene_PVP PVP(width, height);
    Scene_GameOver GameOver(width, height);
    Scene_AI AI(width, height);
    Scene_AIMenu AIMenu(width, height);

    SetTargetFPS(120);

    while (!WindowShouldClose() && !quitGame)
    {
        // Delta time
        float dt = GetFrameTime();

        BeginDrawing();
        ClearBackground(BLACK);

        if (currentScene != targetScene)
        {
            switch (currentScene)
            {
            case -1:
                break;

            case 0: //Main Menu
                MainMenu.Reset();
                break;

            case 1: //AI Menu
                AIMenu.Reset();
                break;

            case 10:
                PVP.Reset();
                break;

            case 20:
                AI.SetDifficulty(1);
                AI.Reset();
                break;

            case 21:
                AI.SetDifficulty(2);
                AI.Reset();
                break;

            case 22:
                AI.SetDifficulty(3);
                AI.Reset();
                break;

            case 99:
                GameOver.Reset();
                break;

            default:
                break;
            }

            currentScene = targetScene;
        };

        switch (currentScene)
        {
        case -1:
            quitGame = true;
            break;

        case 0:
            targetScene = MainMenu.tick(dt);
            break;

        case 1:
            targetScene = AIMenu.tick(dt);
            break;

        case 10:
            targetScene = PVP.tick(dt);
            break;

        case 20:
            targetScene = AI.tick(dt);
            break;

        case 21:
            targetScene = AI.tick(dt);
            break;

        case 22:
            targetScene = AI.tick(dt);
            break;

        case 99:
            targetScene = GameOver.tick(dt);
            break;

        default:
            break;
        }

        EndDrawing();
    }

    CloseWindow();
}