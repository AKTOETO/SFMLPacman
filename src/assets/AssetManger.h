#pragma once

#include <map>
#include <string>
#include "SFML/Graphics/Texture.hpp"

namespace Engine
{
	enum class TEXTURES
	{
		GRASS = 0,
		WALL,
	};

	enum class FONTS
	{
		MAIN_FONT = 0,
	};

	class AssetManager
	{
	protected:
		std::map<TEXTURES, sf::Texture> textures;
		std::map<FONTS, sf::Texture> fonts;

	public:
		AssetManager() {};
		~AssetManager() {};

		bool AddTexture(TEXTURES texture, std::string path);
		bool AddFont(FONTS font, std::string path);
	};

}

