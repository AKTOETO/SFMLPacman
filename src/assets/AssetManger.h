#pragma once
#include "../Constans.h"

#include <map>
#include <string>
#include <iostream>
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"


namespace Engine
{

	class AssetManager
	{
	protected:
		std::map<TEXTURES, sf::Texture> textures;
		std::map<SPRITES, sf::Sprite> sprites;
		std::map<FONTS, sf::Font> fonts;

	public:
		AssetManager();
		~AssetManager();

		bool addTexture(TEXTURES texture, std::string path);
		bool addFont(FONTS font, std::string path);
		bool addSprite(SPRITES sprite, TEXTURES texture, sf::Vector2i size,
					sf::Vector2i startCoords = sf::Vector2i(0, 0));

		sf::Texture& getTexture(TEXTURES texture);
		sf::Font& getFont(FONTS font);
		sf::Sprite& getSprite(SPRITES sprite);
	};

}

