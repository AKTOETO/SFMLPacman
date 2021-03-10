#include "AssetManger.h"
#include <iostream>

bool Engine::AssetManager::AddTexture(TEXTURES id, std::string path)
{
    if (!textures[id].loadFromFile("path"))
    {
        std::cerr << "Texture wasn`t loaded" << std::endl;
        return false;
    }
    else
    {
        
    }
}
