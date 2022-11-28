#include "Scene_MainMenu.h"
#include "raylib.h"

Scene_MainMenu::Scene_MainMenu(int winWidth, int winHeight)
{
    Scene_ID = 0;
    Scene_Selection = 1;
    
    width = winWidth;
    height = winHeight;

    circlePos = Vector2{static_cast<float>(width/2 - 70), static_cast<float>(height/2 - 10)};
}

int Scene_MainMenu::tick(float deltaTime)
{
    DrawText("PONG!", width/2 - 90, height/4, 60, WHITE);
    DrawText("Play VS", width/2 - 45, height/2 - 25, 45, WHITE);
    DrawText("Play AI", width/2 - 45, height/2 + 25, 45, WHITE);
    DrawText("Quit", width/2 - 45, height/2 + 75, 45, WHITE);
    
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
        if(menuSelection < 2) 
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
        Scene_Selection = 1; //Play PVP
        break;

    case 1:
        Scene_Selection = 1; //Play AI
        break;

    case 2:
        Scene_Selection = -1; //Quit Game
        break;
    
    default:
        break;
    }

    if(IsKeyDown(KEY_ENTER))
    {
        return Scene_Selection;
    }
    
    return Scene_ID;
}

void Scene_MainMenu::Reset()
{
    circlePos = Vector2{static_cast<float>(width/2 - 70), static_cast<float>(height/2 - 10)};
    Scene_Selection = 1;
}