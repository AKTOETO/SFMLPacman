#pragma once
#include <map>
#include <memory>
#include "../scenes/BaseScene.h"
//#include "../scenes/MainScene.h"
//#include "../Context.h"

namespace Engine
{
	enum class SCENES
	{
		MAIN_MENU = 0,
		MAIN_GAME,
	};

	class SceneManager
	{
		std::map<SCENES, std::shared_ptr<Engine::BaseScene>> scenesMap;
		std::shared_ptr<Engine::BaseScene> currentScene;
		SCENES currentSceneId;

	public:
		SceneManager();
		~SceneManager() {};

		//bool setScene(SCENES scenesList, std::shared_ptr<Context>& context);
		//std::unique_ptr<BaseScene> getScene();
	};
}

