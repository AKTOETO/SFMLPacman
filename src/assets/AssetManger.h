#pragma once

#include <map>
#include <string>
#include <iostream>
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"

namespace Engine
{
	enum class TEXTURES
	{
		GRASS = 0,
		WALL,
		COIN,
		MAIN_BUTTON,
	};

	enum class FONTS
	{
		MAIN_FONT = 0,
	};

	enum class SPRITES
	{
		MAIN_BUTTON = 0,
		SWITCH_SCENE,
	};

	class AssetManager
	{
	protected:
		std::map<TEXTURES, sf::Texture> textures;
		std::map<SPRITES, sf::Sprite> sprites;
		std::map<FONTS, sf::Font> fonts;

	public:
		AssetManager() { std::cout << "AssetManager constructor\n"; }
		~AssetManager() { std::cout << "AssetManager destructor\n"; }

		bool addTexture(TEXTURES texture, std::string path);
		bool addFont(FONTS font, std::string path);
		bool addSprite(SPRITES sprite, TEXTURES texture, sf::Vector2i size,
					sf::Vector2i startCoords = sf::Vector2i(0, 0));

		sf::Texture& getTexture(TEXTURES texture);
		sf::Font& getFont(FONTS font);
		sf::Sprite& getSprite(SPRITES sprite);
	};

}

