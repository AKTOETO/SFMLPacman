#include "ObjectManager.h"

bool Engine::ObjectManager::addObject(OBJECTS name, std::shared_ptr<Engine::BaseObject> object)
{
	objects[name] = object;
	std::cout << "ahuet\n";
	return true;
}

std::shared_ptr<Engine::BaseObject> Engine::ObjectManager::getObject(OBJECTS object)
{
	return objects[object];
}
