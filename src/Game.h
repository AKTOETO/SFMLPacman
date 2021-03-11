#pragma once
#include "Context.h"
#include "../src/scenes/MainScene.h"


class Game
{
private:
    std::shared_ptr<Context> context;

public:
    Game();
    ~Game();
    void Run();
};

