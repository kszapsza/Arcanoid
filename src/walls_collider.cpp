//
// Created by kszap on 27.09.2020.
//

#include "game.hpp"
#include "walls_collider.hpp"

WallsCollider::WallsCollider(AssetsManager& assets, Ball& ball, Game& game)
		: ball(ball), game(game)
{
	collisionSoundBuffer = assets.getSound("..\\assets\\wall_bounce.wav");
	collisionSound.setBuffer(collisionSoundBuffer);
}

void WallsCollider::checkForCollision()
{
	if (ball.getLeft() < 0 || ball.getRight() > Game::PLAY_AREA_WIDTH)
	{
		ball.bounceX();

		if (collisionSound.getStatus() != sf::Sound::Playing)
			collisionSound.play();
	}
	if (ball.getUp() < 0)
	{
		ball.bounceY();

		if (collisionSound.getStatus() != sf::Sound::Playing)
			collisionSound.play();
	}
}
