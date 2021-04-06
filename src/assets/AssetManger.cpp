#include "AssetManger.h"
#include <iostream>

Engine::AssetManager::AssetManager()
{
}

Engine::AssetManager::~AssetManager()
{
}

bool Engine::AssetManager::addTexture(TEXTURES id, std::string path)
{
    if (textures[id].getSize().x == 0)
    {
        if (!textures[id].loadFromFile("assets/textures/" + path))
        {
            std::cerr << "Texture wasn`t loaded" << std::endl;
            return false;
        }
    }
    return true;
}

bool Engine::AssetManager::addSprite(SPRITES sprite, TEXTURES texture, sf::Vector2i size, sf::Vector2i startCoords)
{
    sprites[sprite].setTexture(textures[texture], true);
    sprites[sprite].setTextureRect(sf::IntRect(startCoords, size));
    return true;
}

bool Engine::AssetManager::addFont(FONTS font, std::string path)
{  
    if (!fonts[font].loadFromFile("assets/fonts/" + path))
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

sf::Sprite& Engine::AssetManager::getSprite(SPRITES sprite)
{
    return sprites[sprite];
}


sf::Texture& Engine::AssetManager::getTexture(TEXTURES texture)
{
    return textures[texture];
}


