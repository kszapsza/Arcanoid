//
// Created by kszap on 26.09.2020.
//

#pragma once

#include "ball.hpp"
#include "paddle.hpp"

class PaddleCollider
{
private:
	Ball& ball;
	Paddle& paddle;

public:
	PaddleCollider(Ball& ball, Paddle& paddle)
			:ball(ball), paddle(paddle)
	{
	}
	void checkForCollision();
};


