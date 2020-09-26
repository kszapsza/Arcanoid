//
// Created by kszap on 26.09.2020.
//

#include "paddle_collider.hpp"

void PaddleCollider::checkForCollision()
{
	if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds()))
		ball.bounce();
}