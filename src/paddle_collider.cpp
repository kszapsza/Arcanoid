//
// Created by kszap on 26.09.2020.
//

#include "paddle_collider.hpp"

/**
 * @brief Checks for ball–paddle collision
 * bounces the ball in Y-axis if collision is detected.
 */
void PaddleCollider::checkForCollision()
{
	if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds()))
		ball.bounce();
}