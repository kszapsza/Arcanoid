//
// Created by kszap on 27.09.2020.
//

#pragma once

#include <SFML\Audio.hpp>
#include "assets_manager.hpp"
#include "ball.hpp"

class Game;

class WallsCollider
{
private:
	Ball& ball;
	Game& game;

	sf::SoundBuffer collision_sound_buffer;
	sf::Sound collision_sound;

public:
	WallsCollider(AssetsManager& assets, Ball& ball, Game& game);
	void checkForCollision();
};


