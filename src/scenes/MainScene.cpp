#include "MainScene.h"

Engine::MainScene::MainScene(std::shared_ptr<Context>& _context) :context(_context)
{
	context->logger->Message("mainscene constructor");
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
		context->window->getSize().y / 2 - 50, TEXTURES::MAIN, SPRITES::MAIN_BUTTON, FONTS::MAIN_FONT,
		2, sf::Vector2i(148, 23), sf::Vector2i(1, 1)));

	//background sprite
	context->assetManager->addSprite(SPRITES::MAIN_BACKGROUND, TEXTURES::MAIN,
		sf::Vector2i( 240, 320 ), sf::Vector2i( 151, 0 ));
	context->assetManager->getSprite(SPRITES::MAIN_BACKGROUND).setScale({ 2,2 });

	context->logger->Message("activate main scene");
}

void Engine::MainScene::processInput(sf::Event event)
{
	context->objectManager->getObject(OBJECTS::MAIN_BUTTON)->processInput(event);
}

void Engine::MainScene::processUpdate(float time)
{
	//button pressed PLAY
	if (context->objectManager->getObject(OBJECTS::MAIN_BUTTON)->processUpdate(time))
	{	
		//context->sceneManager->setScene(Engine::SCENES::GAME_SCENE,std::make_unique<Engine::GameScene>(context));
		deactivate = true;
	}
	if (deactivate == true)
	{
		//PACMAN
		titlePacman.setPosition(titlePacman.getPosition().x,
			titlePacman.getPosition().y - VELOCITY * time);

		//button
		context->objectManager->getObject(Engine::OBJECTS::MAIN_BUTTON)->setPosition(
			context->objectManager->getObject(Engine::OBJECTS::MAIN_BUTTON)->getPosition().x,
			context->objectManager->getObject(Engine::OBJECTS::MAIN_BUTTON)->getPosition().y - VELOCITY * time
		);
	
		//background
		context->assetManager->getSprite(SPRITES::MAIN_BACKGROUND).setPosition(
			context->assetManager->getSprite(SPRITES::MAIN_BACKGROUND).getPosition().x,
			context->assetManager->getSprite(SPRITES::MAIN_BACKGROUND).getPosition().y - VELOCITY * time
		);
	}

}

void Engine::MainScene::processDraw()
{
	context->window->clear(/*sf::Color(2, 100, 255)*/);
	//context->window->draw(context->assetManager->getSprite(SPRITES::SWITCH_SCENE));
	context->window->draw(context->assetManager->getSprite(SPRITES::MAIN_BACKGROUND));
	context->window->draw(titlePacman);
	context->objectManager->getObject(OBJECTS::MAIN_BUTTON)->processDraw();
}
