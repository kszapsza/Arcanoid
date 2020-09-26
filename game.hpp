//
// Created by kszap on 26.09.2020.
//

#pragma once

#include <SFML\Graphics.hpp>

#include "ball.hpp"
#include "block.hpp"
#include "block_collider.hpp"
#include "paddle.hpp"
#include "paddle_collider.hpp"

#include <vector>

constexpr unsigned int window_width = 480;
constexpr unsigned int window_height = 700;

class Game
{
private:
	sf::Texture window_bg_texture;

	Ball ball{ 256.0f, 350.0f };
	Paddle paddle;

	std::vector<std::unique_ptr<Block>> blocks;

	PaddleCollider paddle_collider{ ball, paddle };
	BlockCollider block_collider{ ball, blocks };

public:
	sf::RenderWindow window{ sf::VideoMode(window_width, window_height),
							 "Arcanoid", sf::Style::Close | sf::Style::Titlebar };
	sf::Sprite window_bg;

	Game();
	void update();
};


