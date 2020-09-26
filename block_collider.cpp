//
// Created by kszap on 26.09.2020.
//

#include "block_collider.hpp"

/**
 * @brief Called from game loop, checks for collision between ball and any of the blocks.<br>
 * At most one block may be removed in one iteration.
 */
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
