//
// Created by kszap on 26.09.2020.
//

#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include <map>
#include <string>

/**
 * @brief Assets management class.
 *
 * Using this class, we are sure that each asset is loaded from disk only
 * once when creating some entity. Therefore, we gain huge performance improvement
 * when creating plenty of objects sharing the same asset.<br>
 *
 * The class stores texture objects in std::map, where the key is path of original
 * asset location on local disk. So far the class stores textures only, it may also
 * eventually store other assets as well.
 */

// TODO: Should be implemented as a singleton to be completely sure assets are stored once
//		 and in one place

class AssetsManager
{
public:
	AssetsManager();

	sf::Texture& getTexture(const std::string& path);
	sf::SoundBuffer& getSound(const std::string& path);

private:
	static void tryLoad(sf::Texture& dest, const std::string& location);
	static void tryLoad(sf::SoundBuffer& dest, const std::string& location);

	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::SoundBuffer> sounds;
};


