//
// Created by kszap on 26.09.2020.
//

#include "paddle_collider.hpp"

PaddleCollider::PaddleCollider(AssetsManager& assets, Ball& ball, Paddle& paddle)
		: ball(ball), paddle(paddle)
{
	collision_sound_buffer = assets.getSound("..\\assets\\paddle_bounce.wav");
	collision_sound.setBuffer(collision_sound_buffer);
}

/**
 * @brief Checks for ball–paddle collision
 * bounces the ball in Y-axis if collision is detected.
 */
void PaddleCollider::checkForCollision()
{
	const auto ball_box = ball.getGlobalBounds();
	const auto paddle_box = paddle.getGlobalBounds();

	// Bounce if ball and paddle intersect, but only once (set did_bounce flag)
	if (ball_box.intersects(paddle_box) && !did_bounce)
	{
		ball.bounceY();
		did_bounce = true;

		if (collision_sound.getStatus() != sf::Sound::Playing)
			collision_sound.play();
	}

	// If ball bounced out of the paddle, reset the flag.
	if (!ball_box.intersects(paddle_box))
	{
		did_bounce = false;
	}

	// This prevents ball to glitch, if on the next frame after bounce, ball
	// still intersects the paddle (occured frequently at some angles).
}