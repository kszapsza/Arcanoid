//
// Created by kszap on 26.09.2020.
//

#include "assets_manager.hpp"
#include <iostream>

AssetsManager::AssetsManager()
{
}

void AssetsManager::tryLoad(sf::Texture& dest, const std::string& location)
{
	if (!dest.loadFromFile(location))
	{
		std::cerr << "ERROR: Unable to load window background texture!\n";
		exit(1);
	}
}

sf::Texture& AssetsManager::getTexture(const std::string& path)
{
	const auto& pair_found = textures.find(path);

	if (pair_found != textures.end())
	{
		return pair_found->second;
	}
	else
	{
		auto& texture = textures[path];
		tryLoad(texture, path);
		return texture;
	}
}
