#pragma once
#include <map>
#include <memory>
#include "../scenes/BaseScene.h"
#include "../Constans.h"

namespace Engine
{

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

