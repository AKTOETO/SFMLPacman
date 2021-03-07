#include "Game.h"
#include <iostream>

Game::Game()
{
    context->window->create(sf::VideoMode(640, 360), "SFML works!", sf::Style::Close);
    context->sceneManager->setScene(Engine::SCENES::MAIN_MENU);
	//context = std::make_shared<Context>(Context(*window));
}

void Game::Run()
{
    std::cout << "f" << std::endl;
    /*while (context->window->isOpen())
    {
        sf::Event event;
        while (context->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                context->window->close();
        }

        context->window->clear();
        //window.draw(shape);
        context->window->display();
    }*/
    /*while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();
        window->display();
    }*/
}
