//
// Created by kszap on 26.09.2020.
//

#include "assets_manager.hpp"
#include <iostream>

AssetsManager::AssetsManager()
{
}

/**
 * Internal utility method, which tries to import texture from given destination.
 * At the moment, logs to standard error stream and shuts down entire game if some
 * assets was not loaded successfully.
 *
 * @param dest A reference to the texture object.
 * @param location Desired file path.
 */

void AssetsManager::tryLoad(sf::Texture& dest, const std::string& location)
{
	if (!dest.loadFromFile(location))
	{
		std::cerr << "ERROR: Unable to load window background texture!\n";
		exit(1);
	}
}

/**
 * Looks up textures map for desired texture based on its original path. If texture
 * was already loaded (was found in map), returns texture object immediately.
 * Otherwise, tries to load a texture from local disk and stores it in the map for
 * future usage.
 *
 * @param path Path to original texture location on disk.
 * @return Desired texture object reference.
 */

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
