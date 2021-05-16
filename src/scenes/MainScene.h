#pragma once

#include <iostream>
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"

#include "BaseScene.h"
#include "GameScene.h"
#include "../objects/ButtonObject.h"
#include "../Context.h"
#include "../Constans.h"

namespace Engine
{
	class MainScene : public BaseScene
	{
	private:
		std::shared_ptr<Context> context;

		sf::Text titlePacman;
		bool deactivate = false;

	public:
		MainScene(std::shared_ptr<Context>& _context);
		~MainScene() {};

		void activate() override;

		void processInput(sf::Event) override;
		void processUpdate(float time) override;
		void processDraw() override;
	};

}


