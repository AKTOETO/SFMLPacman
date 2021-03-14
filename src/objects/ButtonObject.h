#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"
#include "../Context.h"
#include "BaseObject.h"

namespace Engine
{
	class ButtonObject : public BaseObject
	{
	private:
		std::shared_ptr<Context> context;
		sf::Text playText;

	public:
		ButtonObject(std::shared_ptr<Context> context, std::string name = "test", float x = 0, float y = 0, TEXTURES texture = TEXTURES::MAIN_BUTTON, SPRITES sprite = SPRITES::MAIN_BUTTON, FONTS font = FONTS::MAIN_FONT, int scale = 5, sf::Vector2i size = sf::Vector2i(100, 100));
		~ButtonObject() { std::cout << "buttonObject destructor\n"; }

		void processInput() override;
		void processUpdate() override;
		void processDraw() override;
	};

}


