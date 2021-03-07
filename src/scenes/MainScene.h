#pragma once

#include <iostream>
#include "../Game.h"
#include "BaseScene.h"

namespace Engine
{
	class MainScene : public BaseScene
	{
	public:
		MainScene(std::unique_ptr<Context> context) { std::cout << "main" << std::endl; }
		~MainScene() {};

		void activate() override;

		void processInput()  override;
		void processUpdate() override;
		void processDraw() override;
	};

}


