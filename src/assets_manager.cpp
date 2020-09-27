//
// Created by kszap on 26.09.2020.
//

#include "assets_manager.hpp"

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

/**
 * Looks up sounds map for desired sound based on its original path. If sound
 * was already loaded (was found in map), returns sound buffer object immediately.
 * Otherwise, tries to load a sound from local disk and stores it in the map for
 * future usage.
 *
 * @param path Path to original sound location on disk.
 * @return Desired sound buffer object reference.
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