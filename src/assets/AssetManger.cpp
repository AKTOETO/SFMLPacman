#include "AssetManger.h"
#include <iostream>

bool Engine::AssetManager::addTexture(TEXTURES id, std::string path)
{
    if (!textures[id].loadFromFile(path))
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

bool Engine::AssetManager::addSprite(SPRITES sprite, TEXTURES texture, sf::Vector2i size, sf::Vector2i startCoords)
{
    sprites[sprite].setTexture(textures[texture], true);
    sprites[sprite].setTextureRect(sf::IntRect(startCoords, size));
    return true;
}

sf::Font& Engine::AssetManager::getFont(FONTS font)
{
    return fonts[font];
}

sf::Sprite& Engine::AssetManager::getSprite(SPRITES sprite)
{
    return sprites[sprite];
}

sf::Texture& Engine::AssetManager::getTexture(TEXTURES texture)
{
    return textures[texture];
}
