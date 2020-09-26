//
// Created by kszap on 26.09.2020.
//

#pragma once

#include <SFML/Graphics.hpp>

#include <map>
#include <string>

class AssetsManager
{
public:
	AssetsManager();
	sf::Texture& getTexture(const std::string& path);

private:
	static void tryLoad(sf::Texture& dest, const std::string& location);
	std::map<std::string, sf::Texture> textures;
};


