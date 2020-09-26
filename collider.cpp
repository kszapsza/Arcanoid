//
// Created by kszap on 26.09.2020.
//

#include "collider.hpp"

void Collider::checkForCollision()
{
	if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds()))
		ball.bounceUp();
}