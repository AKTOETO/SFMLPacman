#pragma once
#include "Context.h"
#include "../src/scenes/MainScene.h"
#include "SFML/System/Clock.hpp"


class Game
{
private:
    sf::Clock clock;
    std::shared_ptr<Context> context;

public:
    Game();
    ~Game();
    void Run();
};

