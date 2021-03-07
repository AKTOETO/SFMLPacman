#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

#include "sceneManager/SceneManager.h"
#include "assets/AssetManger.h"


struct Context {
    std::unique_ptr<sf::RenderWindow> window;
    std::unique_ptr<Engine::SceneManager> sceneManager;
    std::unique_ptr<Engine::AssetManger> assetManager;

    Context()
    {
        window = std::make_unique<sf::RenderWindow>();
        sceneManager = std::make_unique<Engine::SceneManager>(Engine::SceneManager());
        assetManager = std::make_unique<Engine::AssetManger>(Engine::AssetManger());
    }
};

class Game
{
public:
    Game();
    void Run();

private:
    std::shared_ptr<Context> context;
};

