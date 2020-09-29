//
// Created by kszap on 26.09.2020.
//

#include "block_collider.hpp"

BlockCollider::BlockCollider(AssetsManager& assets, Ball& ball, std::vector<std::unique_ptr<Block>>& blocks)
		:ball(ball), blocks(blocks)
{
	collision_sound_buffer = assets.getSound("..\\assets\\block_destroyed.wav");
	collision_sound.setBuffer(collision_sound_buffer);
}

/**
 * @brief Called from game loop, checks for collision between ball and any of the blocks.<br>
 * At most one block may be removed in one iteration.
 *
 * @return True, if collision was detected.
 */
bool BlockCollider::checkForCollision()
{
	for (auto it{ blocks.begin() }; it != blocks.end(); ++it)
	{
		if (ball.getGlobalBounds().intersects((*it)->getGlobalBounds()))
		{
			ball.bounceY();
			blocks.erase(it);
			collision_sound.play();
			return true;
		}
	}

	return false;
}
