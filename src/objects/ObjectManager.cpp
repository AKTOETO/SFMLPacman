#include "ObjectManager.h"

Engine::ObjectManager::ObjectManager()
{
}

Engine::ObjectManager::~ObjectManager()
{
}

bool Engine::ObjectManager::addObject(OBJECTS name, std::shared_ptr<Engine::BaseObject> object)
{
	objects[name] = std::move(object);
	return true;
}

std::shared_ptr<Engine::BaseObject> Engine::ObjectManager::getObject(OBJECTS object)
{
	return objects[object];
}
