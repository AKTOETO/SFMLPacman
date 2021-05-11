#pragma once
#include <map>
#include <memory>
#include "../scenes/BaseScene.h"

namespace Engine
{
	enum class SCENES
	{
		NULL_SCENE = -1,
		MAIN_SCENE = 0,
		GAME_SCENE,
	};

	class SceneManager
	{
		std::map<SCENES, std::unique_ptr<BaseScene>> sceneList;
		SCENES currentScene;

	public:
		SceneManager() {};
		~SceneManager() {};

		bool setScene(SCENES nameScene, std::unique_ptr<BaseScene> scene);
		std::unique_ptr<BaseScene>& getScene(SCENES nameScene = SCENES::NULL_SCENE);
	};
}

