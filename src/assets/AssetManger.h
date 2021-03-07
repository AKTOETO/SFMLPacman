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

	class AssetManger
	{
	protected:
		std::map<TEXTURES, sf::Texture> textures;

	public:
		AssetManger() {};

		bool AddTexture(TEXTURES texture, std::string path);
	};

}

