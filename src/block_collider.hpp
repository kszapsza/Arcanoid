//
// Created by kszap on 26.09.2020.
//

#pragma once

#include <SFML\Audio.hpp>

#include "ball.hpp"
#include "block.hpp"

#include <vector>

/**
 * @brief Ball–block collisions class.
 * Holds references to ball and vector of block pointers.
 */

class BlockCollider
{
private:
	Ball& ball;
	std::vector<std::unique_ptr<Block>>& blocks;

	sf::SoundBuffer collisionSoundBuffer;
	sf::Sound collisionSound;

public:
	BlockCollider(AssetsManager& assets, Ball& ball, std::vector<std::unique_ptr<Block>>& blocks);
	bool checkForCollision();
};


