#ifndef GAMEOVER_INTERFACE
#define GAMEOVER_INTERFACE

#include "Base_Interface.h"

class GameOver_Interface : public Base_Interface
{
public:
    GameOver_Interface(int winWidth, int winHeight);
    virtual int tick(float deltaTime) override;
    virtual void Reset() override;
};

#endif