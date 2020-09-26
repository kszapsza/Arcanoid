//
// Created by kszap on 26.09.2020.
//

#pragma once

#include <SFML\Graphics.hpp>

#include "assets_manager.hpp"
#include "ball.hpp"
#include "block.hpp"
#include "block_collider.hpp"
#include "paddle.hpp"
#include "paddle_collider.hpp"

#include <vector>

constexpr unsigned int window_width = 480;
constexpr unsigned int window_height = 700;

/**
 * @brief Main game class, storing key game data and objects.
 *
 * This class intializes and handles game window, assets manager
 * and all essential game elements, such as: ball, paddle,
 * vector of blocks pointers, neccessary texture references,
 * collission classes and game over/won booleans.
 */

class Game
{
private:
	AssetsManager assets;

	Ball ball;
	Paddle paddle;

	std::vector<std::unique_ptr<Block>> blocks;
	void createBlocks();

	PaddleCollider paddle_collider{ ball, paddle };
	BlockCollider block_collider{ ball, blocks };

	sf::Texture window_bg_texture;
	sf::Texture game_over_texture;
	sf::Texture game_won_texture;

	bool game_over{ false };
	bool game_won{ false };

public:
	sf::RenderWindow window{ sf::VideoMode(window_width, window_height),
							 "Arcanoid", sf::Style::Close | sf::Style::Titlebar }; // NOLINT(hicpp-signed-bitwise)

	sf::Sprite window_bg;
	sf::Sprite game_over_info;
	sf::Sprite game_won_info;

	Game();
	void update();
};


