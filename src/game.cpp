//
// Created by kszap on 26.09.2020.
//

#include "game.hpp"
#include <iostream>

/**
 * @brief Main game class constructor.
 *
 * Sets window, window background, UI prompts textures
 * and properties, prepares gameboard etc.
 */
Game::Game()
{
	window.setFramerateLimit(60u);

	window_bg_texture = assets.getTexture("..\\assets\\background.png");
	window_bg_texture.setRepeated(true);

	window_bg.setTexture(window_bg_texture, true);
	window_bg.setTextureRect({ 0, 0, window_width, window_height });
	window_bg.setScale(1.5f, 1.5f);

	blocks.reserve(80);
	createBlocks();

	game_over_texture = assets.getTexture("..\\assets\\game_over.png");
	game_over_texture.setSmooth(false);

	game_over_info.setTexture(game_over_texture);
	game_over_info.setPosition(0.0f, 250.0f);

	game_won_texture = assets.getTexture("..\\assets\\game_won.png");
	game_won_texture.setSmooth(false);

	game_won_info.setTexture(game_won_texture);
	game_won_info.setPosition(0.0f, 250.0f);

	game_over_sound_buffer = assets.getSound("..\\assets\\game_over.wav");
	game_over_sound.setBuffer(game_over_sound_buffer);

	game_won_sound_buffer = assets.getSound("..\\assets\\game_won.wav");
	game_won_sound.setBuffer(game_won_sound_buffer);
}

/**
 * @brief Creates (or re-creates after restart) a vector of blocks ptrs.
 */
void Game::createBlocks()
{
	blocks.clear();
	blocks.reserve(80);

	for (std::size_t i{}; i < 8; ++i)
	{
		for (std::size_t j{}; j < 10; ++j)
		{
			blocks.emplace_back(std::make_unique<Block>(assets, static_cast<BlockColor>(i),
					(j * Block::width) + Block::width / 2,
					(i * Block::height) + Block::height / 2));
		}
	}
}

/**
 * @brief Main game update method. Checks win/lose conditions,
 * draws essential objects, shows UI screens, restarts game etc.
 */
void Game::update()
{
	if (!game_over && !game_won)
	{
		paddle.update();
		ball.update();

		paddle_collider.checkForCollision();
		block_collider.checkForCollision();
		walls_collider.checkForCollision();
	}

	window.draw(window_bg);
	window.draw(ball);
	window.draw(paddle);

	for (const auto& block : blocks)
	{
		window.draw(*block);
	}

	if (ball.outOfBoard())
	{
		game_over = true;
		window.draw(game_over_info);

		// Play sound only once after lose.
		if (!game_result_sound_played)
			game_over_sound.play();

		game_result_sound_played = true;
	}

	if (blocks.empty())
	{
		game_won = true;
		window.draw(game_won_info);

		// Play sound only once after win.
		if (!game_result_sound_played)
			game_over_sound.play();

		game_result_sound_played = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		createBlocks();

		ball.reInitialize();
		paddle.reInitialize();

		game_over = false;
		game_won = false;
		game_result_sound_played = false;
	}
}