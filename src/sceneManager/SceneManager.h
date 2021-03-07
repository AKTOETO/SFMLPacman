#pragma once
#include <map>
#include <memory>
#include "../scenes/BaseScene.h"

namespace Engine
{
	enum class SCENES
	{
		MAIN_MENU = 0,
		MAIN_GAME,
	};

	class SceneManager
	{
	protected:
		std::map<SCENES, std::shared_ptr<BaseScene>> scenesMap;
		std::shared_ptr<BaseScene> currentScene;
		SCENES currentSceneId;

	public:
		SceneManager();

		bool setScene(SCENES scenesList, Context& context);
		//std::unique_ptr<BaseScene> getScene();
	};
}

