#pragma once
#include "../Context.h"
#include "BaseObject.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"

namespace Engine
{
	class ButtonObject : public BaseObject
	{
	private:
		std::shared_ptr<Context> context;
		sf::Text playText;
		SPRITES spriteID;
		sf::Vector2i mousePos;
		bool isPressedSprite, isPressedFunc, isKeyUpped;

	public:
		ButtonObject(std::shared_ptr<Context> context, std::string name = "test", float xp = 0, float yp = 0,
			TEXTURES texture = TEXTURES::MAIN, SPRITES sprite = SPRITES::MAIN_BUTTON,
			FONTS font = FONTS::MAIN_FONT, int scale = 5,
			sf::Vector2i size = sf::Vector2i(100, 100), sf::Vector2i coords = sf::Vector2i(0, 0));
		~ButtonObject() {};

		void activate() override;

		void processInput(sf::Event) override;
		bool processUpdate(float time) override;
		void processDraw() override;
	};

}


