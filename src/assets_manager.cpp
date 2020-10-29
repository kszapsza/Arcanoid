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
	const auto& pair_found = fonts.find(path);

	if (pair_found != fonts.end())
	{
		return pair_found->second;
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
	const auto& pair_found = sounds.find(path);

	if (pair_found != sounds.end())
	{
		return pair_found->second;
	}
	else
	{
		auto& sound = sounds[path];
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