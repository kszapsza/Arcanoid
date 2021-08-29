//
// Created by kszap on 26.09.2020.
//

/**
 * Following methods look up assets map for desired font/sound/texture, based on
 * its original path. If an asset was already loaded (was found in map), returns
 * asset object immediately. Otherwise, tries to load the asset from local disk
 * and stores it in the map for future usage.
 */

#include "assets_manager.hpp"

/**
 * @param path Path to original font location on disk.
 * @return Desired sound object reference.
 */

sf::Font& AssetsManager::getFont(const std::string& path)
{
	if (const auto& pairFound = fonts.find(path); pairFound != fonts.end())
	{
		return pairFound->second;
	}
	else
	{
		auto& font = fonts[path];
		tryLoad(font, path);
		return font;
	}
}

/**
 * @param path Path to original sound location on disk.
 * @return Desired sound object reference.
 */

sf::SoundBuffer& AssetsManager::getSound(const std::string& path)
{
	const auto& pairFound = sounds.find(path);

	if (pairFound != sounds.end())
	{
		return pairFound->second;
	}
	else
	{
		sf::SoundBuffer& sound = sounds[path];
		tryLoad(sound, path);
		return sound;
	}
}

/**
 * @param path Path to original texture location on disk.
 * @return Desired texture object reference.
 */

sf::Texture& AssetsManager::getTexture(const std::string& path)
{
	const auto& pairFound = textures.find(path);

	if (pairFound != textures.end())
	{
		return pairFound->second;
	}
	else
	{
		auto& texture = textures[path];
		tryLoad(texture, path);
		return texture;
	}
}