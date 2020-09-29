//
// Created by kszap on 27.09.2020.
//

#include "game.hpp"
#include "walls_collider.hpp"

WallsCollider::WallsCollider(AssetsManager& assets, Ball& ball, Game& game)
		:ball(ball), game(game)
{
	collision_sound_buffer = assets.getSound("..\\assets\\wall_bounce.wav");
	collision_sound.setBuffer(collision_sound_buffer);
}

void WallsCollider::checkForCollision()
{
	if (ball.getLeft() < 0 || ball.getRight() > Game::window_width)
	{
		ball.bounceX();

		if (collision_sound.getStatus() != sf::Sound::Playing)
			collision_sound.play();
	}
	if (ball.getUp() < 0)
	{
		ball.bounceY();

		if (collision_sound.getStatus() != sf::Sound::Playing)
			collision_sound.play();
	}
}
