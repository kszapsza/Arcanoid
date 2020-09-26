//
// Created by kszap on 26.09.2020.
//

#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include "assets_manager.hpp"
#include "ball.hpp"
#include "block.hpp"
#include "block_collider.hpp"
#include "paddle.hpp"
#include "paddle_collider.hpp"
#include "walls_collider.hpp"

#include <vector>

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

	// Collission classes

	PaddleCollider paddle_collider{ assets, ball, paddle };
	BlockCollider block_collider{ assets, ball, blocks };
	WallsCollider walls_collider{ assets, ball, *this };

	// Textures & sprites

	sf::Texture window_bg_texture;
	sf::Texture game_over_texture;
	sf::Texture game_won_texture;

	sf::Sprite window_bg;
	sf::Sprite game_over_info;
	sf::Sprite game_won_info;

	// Sound buffers and sounds

	sf::SoundBuffer game_over_sound_buffer;
	sf::SoundBuffer game_won_sound_buffer;

	sf::Sound game_over_sound;
	sf::Sound game_won_sound;

	// Needed to play game over/won sound effect only once in update() loop...
	bool game_result_sound_played{ false };

	bool game_over{ false };
	bool game_won{ false };

public:
	static constexpr unsigned int window_width = 480;
	static constexpr unsigned int window_height = 700;

	sf::RenderWindow window{ sf::VideoMode(window_width, window_height),
							 "Arcanoid", sf::Style::Close | sf::Style::Titlebar }; // NOLINT(hicpp-signed-bitwise)

	Game();
	void update();
};


