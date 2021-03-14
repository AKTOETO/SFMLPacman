#include "ButtonObject.h"

Engine::ButtonObject::ButtonObject(std::shared_ptr<Context> _context, std::string name, float x, float y, TEXTURES texture, SPRITES sprite, FONTS font, int scale, sf::Vector2i size)
{
	context = _context;
	//texture
	context->assetManager->addTexture(texture, "assets/textures/main_button.png");

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

	std::cout << "buttonobject constructor\n";
}

void Engine::ButtonObject::processInput()
{
}

void Engine::ButtonObject::processUpdate()
{
}

void Engine::ButtonObject::processDraw()
{
	context->window->draw(context->assetManager->getSprite(SPRITES::MAIN_BUTTON));
	context->window->draw(playText);
}
