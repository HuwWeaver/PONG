#include "MainMenu_Interface.h"
#include "raylib.h"

MainMenu_Interface::MainMenu_Interface(int winWidth, int winHeight)
{
    GUI_ID = 0;
    GUI_Selection = GUI_ID;
    
    width = winWidth;
    height = winHeight;

    circlePos = Vector2{static_cast<float>(width/2 - 70), static_cast<float>(height/2 - 10)};
}

int MainMenu_Interface::tick(float deltaTime)
{
    DrawText("PONG!", width/2 - 90, height/4, 60, WHITE);
    DrawText("Play", width/2 - 45, height/2 - 25, 45, WHITE);
    DrawText("Quit", width/2 - 45, height/2 + 25, 45, WHITE);

    if (IsKeyDown(KEY_UP)) 
    {
        circlePos.y = height/2 - 10;
        GUI_Selection = 1; //Play
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        circlePos.y = height/2 + 40;
        GUI_Selection = -1; //Quit
    }

    DrawCircle(circlePos.x, circlePos.y, 10, WHITE);

    if(IsKeyDown(KEY_ENTER))
    {
        return GUI_Selection;
    }
    
    return GUI_ID;
}

void MainMenu_Interface::Reset()
{
    circlePos = Vector2{static_cast<float>(width/2 - 70), static_cast<float>(height/2 - 10)};
    GUI_Selection = GUI_ID;
}