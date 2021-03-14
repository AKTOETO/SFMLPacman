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
		//сделать unique
		std::unique_ptr<BaseScene> currentScene;

	public:
		SceneManager();
		~SceneManager() {};
		//SceneManager(const SceneManager&) { std::cout << "copy constructor scene manager\n"; }

		bool setScene(std::unique_ptr<BaseScene> scene);
		std::unique_ptr<BaseScene>& getScene();
	};
}

