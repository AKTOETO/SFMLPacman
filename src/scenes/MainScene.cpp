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
		context->window->getSize().y / 2 - 50, TEXTURES::MAIN_BUTTON, SPRITES::MAIN_BUTTON, FONTS::MAIN_FONT, 2, sf::Vector2i(148, 23), sf::Vector2i(1, 1)));

	//switcher
	context->animationManager->addAnimation(ANIMATION::SWITCH_SCENE, std::make_unique<SwitchAnimation>(context));
	//context->animationManager->addAnimation(ANIMATION::R_SWITCH_SCENE, std::make_unique<SwitchAnimation>(context));

	std::cout << "activate" << std::endl;
}

void Engine::MainScene::processInput(sf::Event event)
{
	context->objectManager->getObject(OBJECTS::MAIN_BUTTON)->processInput(event);
}

void Engine::MainScene::processUpdate(float time)
{
	bool flag = context->animationManager->getAnimation(ANIMATION::SWITCH_SCENE)->processUpdate(time);
	if (context->objectManager->getObject(OBJECTS::MAIN_BUTTON)->processUpdate())
	{
		
		context->animationManager->getAnimation(ANIMATION::SWITCH_SCENE)->play();
		//context->animationManager->getAnimation(ANIMATION::SWITCH_SCENE)->pause();
	}
	if (flag)
	{
		context->sceneManager->setScene(std::make_unique<Engine::GameScene>(context));
	}
	//std::cout << "update\n";
}

void Engine::MainScene::processDraw()
{
	context->window->clear(sf::Color(2, 100, 255));
	context->window->draw(titlePacman);
	context->objectManager->getObject(OBJECTS::MAIN_BUTTON)->processDraw();
	context->animationManager->getAnimation(ANIMATION::SWITCH_SCENE)->processDraw();
}
