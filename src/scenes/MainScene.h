#pragma once

#include <iostream>
#include "SFML/Graphics/Text.hpp"
#include "BaseScene.h"
#include "GameScene.h"
#include "../objects/ButtonObject.h"
#include "../Context.h"

namespace Engine
{
	class MainScene : public BaseScene
	{
	private:
		std::shared_ptr<Context> context;

		sf::Text titlePacman;

	public:
		MainScene(std::shared_ptr<Context>& _context);
		~MainScene() {};

		void activate() override;

		void processInput(sf::Event) override;
		void processUpdate() override;
		void processDraw() override;
	};

}


