#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "scenes/SceneManager.h"
#include "assets/AssetManger.h"
#include "objects/ObjectManager.h"

struct Context {
    std::unique_ptr<sf::RenderWindow> window = NULL;
    std::unique_ptr<Engine::SceneManager> sceneManager = NULL;
    std::unique_ptr<Engine::AssetManager> assetManager = NULL;
    std::unique_ptr<Engine::ObjectManager> objectManager = NULL;

    Context()
    {
        window = std::make_unique<sf::RenderWindow>();
        sceneManager = std::make_unique<Engine::SceneManager>();
        assetManager = std::make_unique<Engine::AssetManager>();
        objectManager = std::make_unique<Engine::ObjectManager>();
        std::cout << "context constructor\n";
    }
};