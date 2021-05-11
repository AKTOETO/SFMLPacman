#include <iostream>

#include "SceneManager.h"

bool Engine::SceneManager::setScene(SCENES nameScene, std::unique_ptr<BaseScene> scene)
{
	/*currentScene = std::move(scene);
	currentScene->activate();*/
	currentScene = nameScene;
	sceneList[currentScene] = std::move(scene);
	sceneList[currentScene]->activate();
	return true;
}

std::unique_ptr<Engine::BaseScene>& Engine::SceneManager::getScene(SCENES nameScene)
{
	if (nameScene != SCENES::NULL_SCENE)
	{
		return sceneList[nameScene];
	}
	return sceneList[currentScene];
}
