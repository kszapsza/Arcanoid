//
// Created by kszap on 26.09.2020.
//

#pragma once

#include "ball.hpp"
#include "block.hpp"

#include <vector>

class BlockCollider
{
private:
	Ball& ball;
	std::vector<std::unique_ptr<Block>>& blocks;

public:
	BlockCollider(Ball& ball, std::vector<std::unique_ptr<Block>>& blocks)
			:ball(ball), blocks(blocks)
	{
	}

	void checkForCollision();
};


