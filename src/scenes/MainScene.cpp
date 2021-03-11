#include "MainScene.h"
#include <SFML/Graphics/Text.hpp>

//перенести в assetman
#include <SFML/Graphics/Font.hpp>
//конец

#include <iostream>

void Engine::MainScene::activate()
{ 
	/*sf::Font font;
	if (!font.loadFromFile("assets/fonts/main.ttf")){}
	text.setFont(font);
	text.setString("Hello world");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);*/

	std::cout << "activate" << std::endl;
}

void Engine::MainScene::processInput()
{
	std::cout << "processInput" << std::endl;
}

void Engine::MainScene::processUpdate()
{
	std::cout << "processUpdate" << std::endl;
}

void Engine::MainScene::processDraw()
{
	std::cout << "processDraw" << std::endl;
	//context->window->draw(text);
}
