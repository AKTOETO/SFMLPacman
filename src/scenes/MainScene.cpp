#include <iostream>
#include "MainScene.h"

#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"

void Engine::MainScene::activate()
{ 
	context->assetManager->addFont(FONTS::MAIN_FONT, "assets/fonts/main.ttf");
	titlePacman.setFont(context->assetManager->getFont(FONTS::MAIN_FONT));
	titlePacman.setString("Pacman");
	titlePacman.setCharacterSize(50);
	titlePacman.setFillColor(sf::Color::Yellow);
	titlePacman.setStyle(sf::Text::Bold | sf::Text::Underlined);
	titlePacman.setOrigin(titlePacman.getLocalBounds().width / 2, titlePacman.getLocalBounds().height / 2);
	titlePacman.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 - 150);

	/* ¬€–≈«¿“‹ ›“Œ Œ“—ﬁƒ¿
	texture.loadFromFile("assets/textures/coin.png", sf::IntRect(0, 0, 6, 7));

	sprite.setTexture(texture);
	sprite.setOrigin(sf::Vector2f(3.f, 3.f));
	sprite.setScale(sf::Vector2f(10.f, 10.f));
	sprite.setPosition(sf::Vector2f(10.f, 50.f));
	sprite.rotate(15.f);
	*/
	std::cout << "activate" << std::endl;
}

void Engine::MainScene::processInput()
{

}

void Engine::MainScene::processUpdate()
{

}

void Engine::MainScene::processDraw()
{

	context->window->draw(titlePacman);
	//context->window->draw(sprite);

}
