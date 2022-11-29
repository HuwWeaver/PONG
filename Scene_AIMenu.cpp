#include "Scene_AIMenu.h"
#include "raylib.h"

Scene_AIMenu::Scene_AIMenu(int winWidth, int winHeight)
{
    sceneID = 1;
    sceneSelection = 20;
    
    width = winWidth;
    height = winHeight;

    circlePos = Vector2{static_cast<float>(width/2 - 70), static_cast<float>(height/2 - 10)};
}

int Scene_AIMenu::tick(float deltaTime)
{
    DrawText("PONG!", width/2 - 90, height/4, 60, WHITE);
    DrawText("Easy", width/2 - 45, height/2 - 25, 45, WHITE);
    DrawText("Medium", width/2 - 45, height/2 + 25, 45, WHITE);
    DrawText("Hard", width/2 - 45, height/2 + 75, 45, WHITE);
    DrawText("Back to Menu", width/2 - 45, height/2 + 125, 45, WHITE);
    
    if(IsKeyDown(KEY_UP) && inputBuffer <= 0.1f)
    {
        if(menuSelection > 0)
        {
            menuSelection--;
            circlePos.y = circlePos.y - 50;
            inputBuffer = 0.2f;
        }
    }
    else if (IsKeyDown(KEY_DOWN) && inputBuffer <= 0.1f)
    {
        if(menuSelection < 3) 
        {
            menuSelection++;
            circlePos.y = circlePos.y + 50;
            inputBuffer = 0.2f;
        }
    }

    inputBuffer -= deltaTime;
    if(inputBuffer < 0) inputBuffer = 0.0f;

    DrawCircle(circlePos.x, circlePos.y, 10, WHITE);
    
    switch (menuSelection)
    {
    case 0:
        sceneSelection = 20; //Easy
        break;

    case 1:
        sceneSelection = 21; //Medium
        break;

    case 2:
        sceneSelection = 22; //Hard
        break;

    case 3:
        sceneSelection = 0; //Return to main menu
        break;
    
    default:
        break;
    }

    if(IsKeyDown(KEY_ENTER) && inputBuffer <= 0.1f)
    {
        return sceneSelection;
    }
    
    return sceneID;
}

void Scene_AIMenu::Reset()
{
    circlePos = Vector2{static_cast<float>(width/2 - 70), static_cast<float>(height/2 - 10)};
    sceneSelection = 20;
    menuSelection = 0;
    inputBuffer = 0.2f;
}