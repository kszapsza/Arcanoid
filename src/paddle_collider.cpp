//
// Created by kszap on 26.09.2020.
//

#include "paddle_collider.hpp"

PaddleCollider::PaddleCollider(AssetsManager& assets, Ball& ball, Paddle& paddle)
		: ball(ball), paddle(paddle)
{
	collisionSoundBuffer = assets.getSound("..\\assets\\paddle_bounce.wav");
	collisionSound.setBuffer(collisionSoundBuffer);
}

/**
 * @brief Checks for ball–paddle collision
 * bounces the ball in Y-axis if collision is detected.
 */
void PaddleCollider::checkForCollision()
{
	const auto ballBox = ball.getGlobalBounds();
	const auto paddleBox = paddle.getGlobalBounds();

	// Bounce if ball and paddle intersect, but only once (set did_bounce flag)
	if (ballBox.intersects(paddleBox) && !didBounce)
	{
		ball.bounceY();
		didBounce = true;

		if (collisionSound.getStatus() != sf::Sound::Playing)
			collisionSound.play();
	}

	// If ball bounced out of the paddle, reset the flag.
	if (!ballBox.intersects(paddleBox))
	{
		didBounce = false;
	}

	// This prevents ball to glitch, if on the next frame after bounce, ball
	// still intersects the paddle (occurred frequently at some angles).
}