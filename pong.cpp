#include <iostream>
#include "raylib.h"
#include "MainMenu_Interface.h"
#include "PVP_Interface.h"
#include "GameOver_Interface.h"

int main()
{
    // Window Dimensions
    int width{1000};
    int height{650};
    InitWindow(width, height, "PONG!");

    int targetGUI{0};
    int currentGUI{0};
    bool quitGame{false};

    MainMenu_Interface MainMenu_GUI(width, height);
    PVP_Interface PVP_GUI(width, height);
    GameOver_Interface GameOver_GUI(width, height);

    SetTargetFPS(120);

    while (!WindowShouldClose() && !quitGame)
    {
        // Delta time
        float dt = GetFrameTime();

        BeginDrawing();
        ClearBackground(BLACK);

        if (currentGUI != targetGUI)
        {
            switch (currentGUI)
            {
            case -1:
                break;

            case 0:
                break;

            case 1:
                PVP_GUI.Reset();
                break;

            case 99:
                GameOver_GUI.Reset();
                break;

            default:
                break;
            }

            currentGUI = targetGUI;
        };

        switch (currentGUI)
        {
        case -1:
            quitGame = true;
            break;

        case 0:
            targetGUI = MainMenu_GUI.tick(dt);
            break;

        case 1:
            targetGUI = PVP_GUI.tick(dt);
            break;

        case 99:
            targetGUI = GameOver_GUI.tick(dt);
            break;

        default:
            break;
        }

        EndDrawing();
    }

    CloseWindow();
}