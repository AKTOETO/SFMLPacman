#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "sceneManager/SceneManager.h"
#include "assets/AssetManger.h"

struct Context {
    std::unique_ptr<sf::RenderWindow> window = NULL;
    std::unique_ptr<Engine::SceneManager> sceneManager = NULL;
    std::unique_ptr<Engine::AssetManager> assetManager = NULL;

    Context()
    {
        window = std::make_unique<sf::RenderWindow>();
        sceneManager = std::make_unique<Engine::SceneManager>();
        assetManager = std::make_unique<Engine::AssetManager>();
        std::cout << "context constructor\n";
    }
};