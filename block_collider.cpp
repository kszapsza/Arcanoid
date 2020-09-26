//
// Created by kszap on 26.09.2020.
//

#include "block_collider.hpp"

void BlockCollider::checkForCollision()
{
	for (auto it{ blocks.begin() }; it != blocks.end(); ++it)
	{
		if (ball.getGlobalBounds().intersects((*it)->getGlobalBounds()))
		{
			ball.bounce();
			blocks.erase(it);
			break;
		}
	}
}
