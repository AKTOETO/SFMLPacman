#pragma once

#include <map>
#include <string>
#include <memory>
#include <iostream>
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Font.hpp"

namespace Engine
{
	enum class TEXTURES
	{
		GRASS = 0,
		WALL,
		COIN,
	};

	enum class FONTS
	{
		MAIN_FONT = 0,
	};

	class AssetManager
	{
	protected:
		std::map<TEXTURES, sf::Texture> textures;
		std::map<FONTS, sf::Font> fonts;

	public:
		AssetManager() { std::cout << "AssetManager constructor\n"; }
		~AssetManager() { std::cout << "AssetManager destructor\n"; }

		bool addTexture(TEXTURES texture, std::string path);
		bool addFont(FONTS font, std::string path);

		sf::Texture& getTexture(TEXTURES texture);
		sf::Font& getFont(FONTS font);
	};

}

