#include <iostream>
#include "Game.h"

Game::Game()
{
    context = std::make_shared<Context>();
    std::cout << "context has enable\n";
    context->window->create(sf::VideoMode(480, 640), "SFML works!", sf::Style::Close);
    std::cout << "window is created\n";
    context->sceneManager->setScene(std::make_unique<Engine::MainScene>(context));
    std::cout << "game constructor\n";
}

Game::~Game()
{
    std::cout << "game destructor\n";
}

void Game::Run()
{
    while (context->window->isOpen())
    {
        sf::Event event;
        while (context->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||
                event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                context->window->close();
        }

        context->window->clear(sf::Color(2, 100, 255));
        context->sceneManager->getScene()->processInput();
        context->sceneManager->getScene()->processUpdate();
        context->sceneManager->getScene()->processDraw();
        context->window->display();
    }
    
}
