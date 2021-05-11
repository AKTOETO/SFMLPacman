#include <iostream>
#include "Game.h"

Game::Game()
{
    clock.restart();
    context = std::make_shared<Context>();
    context->logger->Message("context enable");
    context->window->create(sf::VideoMode(480, 640), "SFML works!", sf::Style::Close);
    //context->window->setFramerateLimit(60);
    context->logger->Message("window is created");

    context->sceneManager->setScene(Engine::SCENES::MAIN_SCENE, std::make_unique<Engine::MainScene>(context));
    context->logger->Message("game constructor");
}

Game::~Game()
{
    context->logger->Message("game destructor");
}

void Game::Run()
{

    while (context->window->isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        time /= 800;
        clock.restart();
        sf::Event event;
        while (context->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||
                event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                context->window->close();
            context->sceneManager->getScene()->processInput(event);
        }
        //std::cout << "time: " << time << std::endl;
        context->sceneManager->getScene()->processUpdate(time);
        context->sceneManager->getScene()->processDraw();
        context->window->display();
    }
    
}
