#pragma once
#include <memory>
#include <iostream>
#include "SFML/Graphics/Text.hpp"

#define VELOCITY 0.5 //0.5


namespace Engine
{
	enum class SCENES
	{
		NULL_SCENE = -1,
		MAIN_SCENE = 0,
		GAME_SCENE,
	};

	enum class TEXTURES
	{
		MAIN = 0,
	};

	enum class FONTS
	{
		MAIN_FONT = 0,
	};

	enum class SPRITES
	{
		MAIN_BUTTON = 0,
		MAIN_BACKGROUND,
		SWITCH_SCENE,
	};

	enum class OBJECTS
	{
		MAIN_BUTTON = 0,
		MAIN_TEXT,
	};

	struct TextStyle
	{
		sf::Font font;
		std::string text;
		int characterSize;
		sf::Color color;
		sf::Uint32 style;
		sf::Vector2i pos;

		TextStyle()
		{
			//font.loadFromFile("arial.ttf");
			text = "text";
			characterSize = 20;
			color = sf::Color::Cyan;
			style = sf::Text::Italic;
			pos = {0, 0};
		}
	};
}