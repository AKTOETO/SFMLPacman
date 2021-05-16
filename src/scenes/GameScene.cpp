#include "GameScene.h"

Engine::GameScene::GameScene(std::shared_ptr<Context>& _context)
	:context(_context)
{
	context->logger->Message("gamescene constructor");
}

void Engine::GameScene::activate()
{
	scoreState = "score:";
	scoreNum = 0;
	p_deactivate = false;


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

void Engine::GameScene::deactivate()
{
	p_deactivate = true;
}

bool Engine::GameScene::get_status()
{
	return false;
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
		else if (event.key.code == sf::Keyboard::D)
		{
			scoreNum--;
		}
	}
}

void Engine::GameScene::processUpdate(float time)
{
	//std::string chScoreNum = std::to_string(scoreNum);
	score.setString(scoreState + std::to_string(scoreNum));
}

void Engine::GameScene::processDraw()
{
	context->window->clear(sf::Color(1, 10, 10));
	context->window->draw(score);
}
