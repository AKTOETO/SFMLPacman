#include "TextObject.h"

Engine::TextObject::TextObject(std::shared_ptr<Context> _context, TextStyle& t_style)
{
	context = _context;
	/*text.setFont(context->assetManager->getFont(FONTS::MAIN_FONT));
	text.setPosition(100, 100);
	text.setString("JOPA");
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Yellow);*/
	x = t_style.pos.x;
	y = t_style.pos.y;

	context->assetManager->addFont(t_style.font, "main.ttf");
	text.setFont(context->assetManager->getFont(t_style.font));
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
	text.setPosition(x, y);
	return false;
}

void Engine::TextObject::processDraw()
{
	context->window->draw(text);
}
