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

	class AssetManager
	{
	protected:
		std::map<TEXTURES, sf::Texture> textures;

	public:
		AssetManager() {};
		~AssetManager() {};

		bool AddTexture(TEXTURES texture, std::string path);
	};

}

