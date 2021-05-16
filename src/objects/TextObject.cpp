#include "TextObject.h"

Engine::TextObject::TextObject(std::shared_ptr<Context> _context, TextStyle t_style)
{
	context = _context;
	x = t_style.pos.x;
	y = t_style.pos.y;

	context->assetManager->addFont(FONTS::MAIN_FONT, "main.ttf");
	text.setFont(t_style.font);
	text.setString(t_style.text);
	text.setCharacterSize(t_style.characterSize);
	text.setFillColor(t_style.color);
	text.setStyle(t_style.style);
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
	text.setPosition(x, y);
}

void Engine::TextObject::activate()
{
}

void Engine::TextObject::processInput(sf::Event)
{
}

bool Engine::TextObject::processUpdate(float time)
{
	return false;
}

void Engine::TextObject::processDraw()
{
	context->window->draw(text);
}
