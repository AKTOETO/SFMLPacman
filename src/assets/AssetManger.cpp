#include "AssetManger.h"
#include <iostream>

bool Engine::AssetManager::addTexture(TEXTURES id, std::string path)
{
    if (!textures[id].loadFromFile("path"))
    {
        std::cerr << "Texture wasn`t loaded" << std::endl;
        return false;
    }

    return true;
}

bool Engine::AssetManager::addFont(FONTS font, std::string path)
{  
    if (!fonts[font].loadFromFile(path))
    {
        std::cerr << "Font wasn`t loaded" << std::endl;
        return false;
    }

    return true;
}

sf::Font& Engine::AssetManager::getFont(FONTS font)
{
    return fonts[font];
}

sf::Texture& Engine::AssetManager::getTexture(TEXTURES texture)
{
    return textures[texture];
}
