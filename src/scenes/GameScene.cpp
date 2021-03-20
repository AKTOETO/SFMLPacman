#include "GameScene.h"

Engine::GameScene::GameScene(std::shared_ptr<Context>& _context)
	:context(_context), scoreState("score:"), scoreNum(0)
{
	std::cout << "gamescene constructor" << std::endl;
}

void Engine::GameScene::activate()
{
	context->assetManager->addFont(FONTS::MAIN_FONT, "main.ttf");
	score.setFont(context->assetManager->getFont(FONTS::MAIN_FONT));	
	score.setString(scoreState);
	score.setCharacterSize(25);
	score.setFillColor(sf::Color::Yellow);
	score.setStyle(sf::Text::Bold);
	score.setOrigin(score.getLocalBounds().width / 2, score.getLocalBounds().height / 2);
	score.setPosition(score.getGlobalBounds().width / 2 + 10,
		score.getGlobalBounds().height / 2 + 5);
}

void Engine::GameScene::processInput(sf::Event event)
{
	//тестовый код
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::A)
		{
			scoreNum++;
		}
	}
}

void Engine::GameScene::processUpdate()
{
	//std::string chScoreNum = std::to_string(scoreNum);
	score.setString(scoreState + std::to_string(scoreNum));
}

void Engine::GameScene::processDraw()
{
	context->window->clear(sf::Color(1, 10, 10));
	context->window->draw(score);
}
