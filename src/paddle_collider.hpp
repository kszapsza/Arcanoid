//
// Created by kszap on 26.09.2020.
//

#pragma once

#include <SFML/Audio.hpp>

#include "assets_manager.hpp"
#include "ball.hpp"
#include "paddle.hpp"

/**
 * @brief Ball–paddle collisions class.
 * Holds references to ball and paddle objects.
 */

class PaddleCollider
{
private:
	Ball& ball;
	Paddle& paddle;

	sf::SoundBuffer collision_sound_buffer;
	sf::Sound collision_sound;

	// Flag that will make ball bounce up only once per single paddle/ball collision.
	bool did_bounce{ false };

public:
	PaddleCollider(AssetsManager& assets, Ball& ball, Paddle& paddle);
	void checkForCollision();
};


