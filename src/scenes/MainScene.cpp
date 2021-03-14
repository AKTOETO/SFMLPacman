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
	context->assetManager->addFont(FONTS::MAIN_FONT, "assets/fonts/main.ttf");
	titlePacman.setFont(context->assetManager->getFont(FONTS::MAIN_FONT));
	titlePacman.setString("Pacman");
	titlePacman.setCharacterSize(50);
	titlePacman.setFillColor(sf::Color::Yellow);
	titlePacman.setStyle(sf::Text::Bold | sf::Text::Underlined);
	titlePacman.setOrigin(titlePacman.getLocalBounds().width / 2, titlePacman.getLocalBounds().height / 2);
	titlePacman.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 - 150);

	//button PLAY
	context->assetManager->addTexture(TEXTURES::MAIN_BUTTON, "assets/textures/main_button.png");
	context->assetManager->addSprite(SPRITES::MAIN_BUTTON, TEXTURES::MAIN_BUTTON, sf::Vector2i(50, 8));
	context->assetManager->getSprite(SPRITES::MAIN_BUTTON).setOrigin(
		sf::Vector2f(context->assetManager->getSprite(SPRITES::MAIN_BUTTON).getGlobalBounds().width / 2,
					context->assetManager->getSprite(SPRITES::MAIN_BUTTON).getGlobalBounds().height / 2));
	context->assetManager->getSprite(SPRITES::MAIN_BUTTON).setPosition(context->window->getSize().x / 2,
																		context->window->getSize().y / 2 - 50);
	context->assetManager->getSprite(SPRITES::MAIN_BUTTON).setScale(5, 5);	
	context->objectManager->addObject(OBJECTS::MAIN_BUTTON, std::make_shared<Engine::ButtonObject>(context));

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
	context->objectManager->getObject(OBJECTS::MAIN_BUTTON)->processDraw();

}
