#include <iostream>
#include "raylib.h"
#include "Base_Scene.h"
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

    bool quitGame{false};

    Scene_MainMenu MainMenu(width, height); //Scene Num 0
    Scene_PVP PVP(width, height);           //Scene Num 10
    Scene_AIMenu AIMenu(width, height);     //Scene Num 1
    Scene_AI AI(width, height);             //Scene Num 20 (Easy), 21 (Medium), 22 (Hard)
    Scene_GameOver GameOver(width, height); //Scene Num 99

    Base_Scene *currentScene = &MainMenu;
    int targetSceneNum{0};
    int currentSceneNum{0};

    SetTargetFPS(120);

    while (!WindowShouldClose() && !quitGame)
    {
        // Delta time
        float dt = GetFrameTime();

        BeginDrawing();
        ClearBackground(BLACK);

        if (currentSceneNum != targetSceneNum)
        {          
            //Set Difficulty of AI scene in preperation for Scene Reset and Entry into New Scene
            switch (currentSceneNum)
            {
            case 20:
                AI.SetDifficulty(1);
                break;

            case 21:
                AI.SetDifficulty(2);
                break;

            case 22:
                AI.SetDifficulty(3);
                break;

            default:
                break;
            }
            
            //Reset scene that's being exited
            currentScene->Reset();

            //Switch current scene to targeted scene
            switch (targetSceneNum)
            {
            case 0:
                currentScene = &MainMenu;
                break;

            case 1:
                currentScene = &AIMenu;
                break;

            case 10:
                currentScene = &PVP;
                break;

            case 20:
                currentScene = &AI;
                break;

            case 21:
                currentScene = &AI;
                break;

            case 22:
                currentScene = &AI;
                break;

            case 99:
                currentScene = &GameOver;
                break;

            default:
                break;
            }

            currentSceneNum = targetSceneNum;
        };

        //Tick current scene, return target scene number
        targetSceneNum = currentScene->tick(dt);

        //If target scene num = -1, quit game
        if(targetSceneNum == -1)
        {
            quitGame = true;
        }

        EndDrawing();
    }

    CloseWindow();
}