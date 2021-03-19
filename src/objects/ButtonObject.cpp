#include "ButtonObject.h"

Engine::ButtonObject::ButtonObject(std::shared_ptr<Context> _context, std::string name, float x, float y, TEXTURES texture, SPRITES sprite, FONTS font, int scale, sf::Vector2i size)
	:isPressedFunc(false), isPressedSprite(false), isKeyUpped(false), spriteID(sprite), mousePos({0, 0})
{
	context = _context;
	//texture
	context->assetManager->addTexture(texture, "main_button.png");

	//sprite
	context->assetManager->addSprite(sprite, texture, size);
	context->assetManager->getSprite(sprite).setOrigin(
		sf::Vector2f(context->assetManager->getSprite(sprite).getGlobalBounds().width / 2, context->assetManager->getSprite(sprite).getGlobalBounds().height / 2));
	context->assetManager->getSprite(sprite).setPosition(x, y);
	context->assetManager->getSprite(sprite).setScale(scale, scale);

	//text
	playText.setFont(context->assetManager->getFont(font));
	playText.setString(name);
	playText.setCharacterSize(25);
	playText.setFillColor(sf::Color::Yellow);
	playText.setOrigin(playText.getLocalBounds().width / 2, playText.getLocalBounds().height / 2);
	playText.setPosition(x, y - 9);

	std::cout << "Button Object constructor\n";
}

void Engine::ButtonObject::processInput(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed) 
	{ 
		mousePos = { event.mouseButton.x, event.mouseButton.y };
		isPressedFunc = true;
		isPressedSprite = true;
	}
	else
	{
		isPressedFunc = false;
		isPressedSprite = false;
	}

	if (event.type == sf::Event::MouseButtonReleased)
	{
		isKeyUpped = true;
	}
	else
	{
		isKeyUpped = false;
	}
}

bool Engine::ButtonObject::processUpdate()
{
	if (context->assetManager->getSprite(spriteID).getGlobalBounds().contains(
		context->window->mapPixelToCoords(mousePos)))
	{
		if (isPressedFunc)
		{
			// переключение сцены на следующую
			//std::cout <<"mouse coords: "<<mousePos.x<<" "<<mousePos.y<< " Pressed\n";
			isPressedFunc = false;
		
		}
		if (isKeyUpped)
		{
			//std::cout << "released\n";
			isKeyUpped = false;
			return true;
		}
		if (isPressedSprite)
		{
			context->assetManager->getSprite(SPRITES::MAIN_BUTTON).setColor({ 192, 192, 192 });
		}
		else
		{
			context->assetManager->getSprite(SPRITES::MAIN_BUTTON).setColor({ 255, 255, 255 });
		}
	}
	return false;
}

void Engine::ButtonObject::processDraw()
{
	context->window->draw(context->assetManager->getSprite(SPRITES::MAIN_BUTTON));
	context->window->draw(playText);
}
