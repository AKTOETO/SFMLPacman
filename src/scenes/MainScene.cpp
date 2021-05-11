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
		context->window->getSize().y / 2 - 50, TEXTURES::MAIN, SPRITES::MAIN_BUTTON, FONTS::MAIN_FONT, 2, sf::Vector2i(148, 23), sf::Vector2i(1, 1)));

	//std::cout << "activate" << std::endl;
	context->logger->Message("activate main scene");
}

void Engine::MainScene::processInput(sf::Event event)
{
	context->objectManager->getObject(OBJECTS::MAIN_BUTTON)->processInput(event);
}

void Engine::MainScene::processUpdate(float time)
{
	//нажание кнопки PLAY
	if (context->objectManager->getObject(OBJECTS::MAIN_BUTTON)->processUpdate(time))
	{	
		context->sceneManager->setScene(Engine::SCENES::GAME_SCENE,std::make_unique<Engine::GameScene>(context));
	}

}

void Engine::MainScene::processDraw()
{
	context->window->clear(sf::Color(2, 100, 255));
	context->window->draw(titlePacman);
	context->objectManager->getObject(OBJECTS::MAIN_BUTTON)->processDraw();
	//context->animationManager->getAnimation(ANIMATION::SWITCH_SCENE)->processDraw();
}
