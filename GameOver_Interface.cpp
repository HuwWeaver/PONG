#include "GameOver_Interface.h"
#include "raylib.h"

GameOver_Interface::GameOver_Interface(int winWidth, int winHeight)
{
    GUI_ID = 99;
    GUI_Selection = GUI_ID;
    
    width = winWidth;
    height = winHeight;
}

int GameOver_Interface::tick(float deltaTime)
{
    DrawText("Game Over!", width / 2 - 100, height / 2 - 50, 50, RED);

    DrawText("Press R to Restart", width / 2 - 100, height / 2 + 35, 20, BLUE);
    DrawText("or M to Return to Menu", width / 2 - 100, height / 2 + 55, 20, BLUE);

    if (IsKeyDown(KEY_R)) // Restart game on R key press
    {
        GUI_Selection = 1;
    }

    if (IsKeyDown(KEY_M))
    {
        GUI_Selection = 0;
    }
    
    return GUI_Selection;
}

void GameOver_Interface::Reset()
{
    GUI_Selection = GUI_ID;
}