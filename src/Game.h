#pragma once
#include "Context.h"


class Game
{
public:
    Game();
    ~Game();
    void Run();

private:
    std::shared_ptr<Context> context;
};

