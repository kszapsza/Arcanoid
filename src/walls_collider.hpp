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

	sf::SoundBuffer collisionSoundBuffer;
	sf::Sound collisionSound;

public:
	WallsCollider(AssetsManager& assets, Ball& ball, Game& game);
	void checkForCollision();
};


