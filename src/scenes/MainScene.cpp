#include "MainScene.h"

Engine::MainScene::MainScene(std::shared_ptr<Context>& _context) :context(_context)
{
	context->logger->Message("mainscene constructor");
}

void Engine::MainScene::activate()
{ 
	p_deactivate = false;

	//PACMAN
	TextStyle tx;
	tx.font = FONTS::MAIN_FONT;
	tx.text = "Pacman";
	tx.characterSize = 50;
	tx.color = sf::Color::Yellow;
	tx.style = sf::Text::Bold | sf::Text::Underlined;
	tx.pos = sf::Vector2i( context->window->getSize().x / 2, context->window->getSize().y / 2 - 150 );

	context->objectManager->addObject(OBJECTS::MAIN_TEXT, std::make_shared<Engine::TextObject>(context, tx));


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


	//switcher
	context->assetManager->addSprite(SPRITES::SWITCH_BACKGROUND, TEXTURES::MAIN,
		sf::Vector2i(240, 320), sf::Vector2i(240 + 151 + 1, 0));
	context->assetManager->getSprite(SPRITES::SWITCH_BACKGROUND).setScale({ 2,2 });

}

void Engine::MainScene::deactivate()
{
	p_deactivate = true;
}

bool Engine::MainScene::get_status()
{
	return p_deactivate;
}

void Engine::MainScene::processInput(sf::Event event)
{
	context->objectManager->getObject(OBJECTS::MAIN_BUTTON)->processInput(event);
}

void Engine::MainScene::processUpdate(float time)
{
	//button pressed PLAY
	if (context->objectManager->getObject(OBJECTS::MAIN_BUTTON)->processUpdate(time) || p_deactivate == true)
	{	
		
		p_deactivate = true;
	}
	if (p_deactivate == true)
	{
		
		//PACMAN		
		context->objectManager->getObject(OBJECTS::MAIN_TEXT)->setPosition(
			context->objectManager->getObject(OBJECTS::MAIN_TEXT)->getPosition().x,
			context->objectManager->getObject(OBJECTS::MAIN_TEXT)->getPosition().y - VELOCITY * time
		);
		context->objectManager->getObject(OBJECTS::MAIN_TEXT)->processUpdate(time);

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
		if (abs(context->assetManager->getSprite(SPRITES::MAIN_BACKGROUND).getPosition().y)
			> context->window->getSize().y)
		{
			p_deactivate = false;
			context->sceneManager->setScene(SCENES::GAME_SCENE, std::make_unique<Engine::GameScene>(context));
		}
		
	}

}

void Engine::MainScene::processDraw()
{
	context->window->clear(/*sf::Color(2, 100, 255)*/);
	context->window->draw(context->assetManager->getSprite(SPRITES::SWITCH_BACKGROUND));

	context->window->draw(context->assetManager->getSprite(SPRITES::MAIN_BACKGROUND));
	context->objectManager->getObject(OBJECTS::MAIN_BUTTON)->processDraw();
	context->objectManager->getObject(OBJECTS::MAIN_TEXT)->processDraw();
}
