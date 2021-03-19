#include "MainScene.h"

#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"

Engine::MainScene::MainScene(std::shared_ptr<Context>& _context) :context(_context)
{
	std::cout << "mainscene constructor" << std::endl; 
}

void Engine::MainScene::activate()
{ 
	//PACMAN
	context->assetManager->addFont(FONTS::MAIN_FONT, "main.ttf");
	titlePacman.setFont(context->assetManager->getFont(FONTS::MAIN_FONT));
	titlePacman.setString("Pacman");
	titlePacman.setCharacterSize(50);
	titlePacman.setFillColor(sf::Color::Yellow);
	titlePacman.setStyle(sf::Text::Bold | sf::Text::Underlined);
	titlePacman.setOrigin(titlePacman.getLocalBounds().width / 2, titlePacman.getLocalBounds().height / 2);
	titlePacman.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 - 150);

	//button PLAY
	context->objectManager->addObject(OBJECTS::MAIN_BUTTON, std::make_shared<Engine::ButtonObject>(
		context, "PLAY", context->window->getSize().x / 2,
		context->window->getSize().y / 2 - 50, TEXTURES::MAIN_BUTTON, SPRITES::MAIN_BUTTON, FONTS::MAIN_FONT, 5, sf::Vector2i(49, 8)));

	std::cout << "activate" << std::endl;
}

void Engine::MainScene::processInput(sf::Event event)
{
	context->objectManager->getObject(OBJECTS::MAIN_BUTTON)->processInput(event);
}

void Engine::MainScene::processUpdate()
{
	context->objectManager->getObject(OBJECTS::MAIN_BUTTON)->processUpdate();
	//менять сцену
}

void Engine::MainScene::processDraw()
{

	context->window->draw(titlePacman);
	context->objectManager->getObject(OBJECTS::MAIN_BUTTON)->processDraw();

}
