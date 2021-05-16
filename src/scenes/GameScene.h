#pragma once
#include <iostream>
#include "SFML/Graphics/Text.hpp"
#include "BaseScene.h"
#include "../objects/ButtonObject.h"
#include "../Context.h"

namespace Engine
{
	class GameScene : public BaseScene
	{
	private:
		std::shared_ptr<Context> context;
		sf::Text score;
		std::string scoreState;
		int scoreNum;
		bool p_deactivate;

	public:
		GameScene(std::shared_ptr<Context>& _context);
		~GameScene() {};

		void activate() override;
		void deactivate() override;
		bool get_status() override;

		void processInput(sf::Event) override;
		void processUpdate(float time) override;
		void processDraw() override;

	};
}


