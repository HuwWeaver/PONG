#include "Scene_GameOver.h"
#include "raylib.h"

Scene_GameOver::Scene_GameOver(int winWidth, int winHeight)
{
    Scene_ID = 99;
    Scene_Selection = Scene_ID;
    
    width = winWidth;
    height = winHeight;
}

int Scene_GameOver::tick(float deltaTime)
{
    DrawText("Game Over!", width / 2 - 100, height / 2 - 50, 50, RED);

    DrawText("Press R to Restart", width / 2 - 100, height / 2 + 35, 20, BLUE);
    DrawText("or M to Return to Menu", width / 2 - 100, height / 2 + 55, 20, BLUE);

    if (IsKeyDown(KEY_R)) // Restart game on R key press
    {
        Scene_Selection = 1;
    }

    if (IsKeyDown(KEY_M))
    {
        Scene_Selection = 0;
    }
    
    return Scene_Selection;
}

void Scene_GameOver::Reset()
{
    Scene_Selection = Scene_ID;
}