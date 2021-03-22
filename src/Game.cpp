#include <iostream>
#include "Game.h"

Game::Game()
{
    clock.restart();
    context = std::make_shared<Context>();
    std::cout << "context has enable\n";
    context->window->create(sf::VideoMode(480, 640), "SFML works!", sf::Style::Close);
    //context->window->setFramerateLimit(60);
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
        std::cout << "time: " << time << std::endl;
        context->sceneManager->getScene()->processUpdate(time);
        context->sceneManager->getScene()->processDraw();
        context->window->display();
    }
    
}
