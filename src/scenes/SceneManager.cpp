#include <iostream>

#include "SceneManager.h"

Engine::SceneManager::SceneManager()
{
}

bool Engine::SceneManager::setScene(std::unique_ptr<BaseScene> scene)
{
	//scenesMap[SCENES::MAIN_MENU] = move(scene);
	currentScene = std::move(scene);
	currentScene->activate();
	return true;
}

std::unique_ptr<Engine::BaseScene>& Engine::SceneManager::getScene()
{
	return currentScene;
}
