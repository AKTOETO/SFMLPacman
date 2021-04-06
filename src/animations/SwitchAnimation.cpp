#include "SwitchAnimation.h"
#include <cmath>

Engine::SwitchAnimation::SwitchAnimation(std::shared_ptr<Context>& _context)
	:curAngle(90.f), context(_context), direction(-1), countSteps(0)
{
	isPlay = false;
	context->assetManager->addTexture(TEXTURES::MAIN_BUTTON, "main_button.png");
	context->assetManager->addSprite(SPRITES::SWITCH_SCENE, TEXTURES::MAIN_BUTTON,
		sf::Vector2i({ 30,60 }), sf::Vector2i({ 2, 27 }));
	context->assetManager->getSprite(SPRITES::SWITCH_SCENE).setScale(20, 20);
	context->assetManager->getSprite(SPRITES::SWITCH_SCENE).setOrigin(
		context->assetManager->getSprite(SPRITES::SWITCH_SCENE).getLocalBounds().width,
		context->assetManager->getSprite(SPRITES::SWITCH_SCENE).getLocalBounds().height / 3
	);
	context->assetManager->getSprite(SPRITES::SWITCH_SCENE).setPosition(
		context->window->getSize().x / 2, 0
	);
	context->assetManager->getSprite(SPRITES::SWITCH_SCENE).setRotation(curAngle);
}

void Engine::SwitchAnimation::play()
{
	isPlay = true;
}

void Engine::SwitchAnimation::pause()
{
	isPlay = false;
}

bool Engine::SwitchAnimation::processUpdate(float time)
{
	//std::cout << "time: " << time << std::endl;
	if (isPlay)
	{
		curAngle += 0.1 * time * direction;
		if (curAngle > 90 || curAngle <= 0)
		{ 
			direction *= -1;
			countSteps++;
		}
	}
	context->assetManager->getSprite(SPRITES::SWITCH_SCENE).setRotation(curAngle);
	//std::cout << "steps: " << countSteps << std::endl;
	if (countSteps >= 1)return true;
	else return false;
	//std::cout << "direction: "<< direction<<" isplay: "<<isPlay<<" angle: "<<curAngle<<" anim update\n";
}

void Engine::SwitchAnimation::processDraw()
{
	if(isPlay)context->window->draw(context->assetManager->getSprite(SPRITES::SWITCH_SCENE));
}

float Engine::SwitchAnimation::getCountSteps()
{
	return countSteps;
}
