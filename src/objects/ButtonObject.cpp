#include "ButtonObject.h"

Engine::ButtonObject::ButtonObject(std::shared_ptr<Context> _context, std::string name, float xp, float yp,
	TEXTURES texture, SPRITES _sprite, FONTS font, int scale, sf::Vector2i size, sf::Vector2i coords)
	:isPressedFunc(false), isPressedSprite(false), isKeyUpped(false), spriteID(_sprite), mousePos({0, 0})
{
	x = xp;
	y = yp;
	context = _context;
	//font
	context->assetManager->addFont(FONTS::MAIN_FONT, "main.ttf");
	
	//texture
	context->assetManager->addTexture(texture, "main_button.png");

	//sprite
	context->assetManager->addSprite(spriteID, texture, size, coords);
	context->assetManager->getSprite(spriteID).setOrigin(
		sf::Vector2f(context->assetManager->getSprite(spriteID).getLocalBounds().width / 2,
			context->assetManager->getSprite(spriteID).getLocalBounds().height / 2));
	context->assetManager->getSprite(spriteID).setPosition(x, y);
	context->assetManager->getSprite(spriteID).setScale(scale, scale);

	//text
	playText.setFont(context->assetManager->getFont(font));
	playText.setString(name);
	playText.setCharacterSize(25);
	playText.setFillColor(sf::Color::Yellow);
	playText.setOrigin(playText.getLocalBounds().width / 2, playText.getLocalBounds().height / 2);
	playText.setPosition(x, y - context->assetManager->getSprite(spriteID).getLocalBounds().height / 3);

	//std::cout << "Button Object constructor\n";
	context->logger->Message("button Object constructor");
}

void Engine::ButtonObject::activate()
{
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

bool Engine::ButtonObject::processUpdate(float time)
{
	context->assetManager->getSprite(spriteID).setPosition(x, y);
	playText.setPosition(x, y - context->assetManager->getSprite(spriteID).getLocalBounds().height / 3);
	//context->logger->Message("set pos");

	if (context->assetManager->getSprite(spriteID).getGlobalBounds().contains(
		context->window->mapPixelToCoords(mousePos)))
	{
		//context->logger->Message("hovered");
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
			context->assetManager->getSprite(spriteID).setColor({ 192, 192, 192 });
		}
		else
		{
			context->assetManager->getSprite(spriteID).setColor({ 255, 255, 255 });
		}
	}
	return false;
}

void Engine::ButtonObject::processDraw()
{
	context->window->draw(context->assetManager->getSprite(spriteID));
	context->window->draw(playText);
}
