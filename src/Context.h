#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "sceneManager/SceneManager.h"
#include "assets/AssetManger.h"

struct Context {
    std::unique_ptr<sf::RenderWindow> window;
    std::unique_ptr<Engine::SceneManager> sceneManager;
    std::unique_ptr<Engine::AssetManager> assetManager;

    Context()
    {
        window = std::make_unique<sf::RenderWindow>();
        sceneManager = std::make_unique<Engine::SceneManager>(Engine::SceneManager());
        assetManager = std::make_unique<Engine::AssetManager>(Engine::AssetManager());
        std::cout << "context\n";
    }
};