#ifndef MAINMENU_INTERFACE
#define MAINMENU_INTERFACE

#include "Base_Interface.h"

class MainMenu_Interface : public Base_Interface
{
public:
    MainMenu_Interface(int winWidth, int winHeight);
    virtual int tick(float deltaTime) override;
    virtual void Reset() override;

private:
    Vector2 circlePos{};

};

#endif