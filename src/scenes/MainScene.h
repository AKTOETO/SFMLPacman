#pragma once

#include <iostream>
#include "BaseScene.h"
#include "../Context.h"

namespace Engine
{
	class MainScene : public BaseScene
	{
	private:
		std::shared_ptr<Context> context;

	public:
		MainScene(std::shared_ptr<Context> _context) :context(_context) { std::cout << "main" << std::endl; }
		~MainScene() {};

		void activate() override;

		void processInput()  override;
		void processUpdate() override;
		void processDraw() override;
	};

}


