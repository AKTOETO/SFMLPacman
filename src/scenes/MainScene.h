#pragma once

#include <iostream>
#include "SFML/Graphics/Text.hpp"
#include "BaseScene.h"
#include "../Context.h"

namespace Engine
{
	class MainScene : public BaseScene
	{
	private:
		std::shared_ptr<Context> context;

		sf::Text titlePacman;

		sf::Texture texture;
		sf::Sprite sprite;
	public:
		MainScene(std::shared_ptr<Context>& _context) :context(_context) { std::cout << "mainscene constructor" << std::endl; }
		~MainScene() {};

		void activate() override;

		void processInput() override;
		void processUpdate() override;
		void processDraw() override;
	};

}


