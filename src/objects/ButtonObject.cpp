#include "ButtonObject.h"

Engine::ButtonObject::ButtonObject(std::shared_ptr<Context> _context)
{	
	context = _context;
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
}
