//
// Created by kszap on 26.09.2020.
//

#include "game.hpp"
#include <iostream>

Game::Game()
{
	window.setFramerateLimit(60u);
	window_bg_texture.setRepeated(true);

	if (!window_bg_texture.loadFromFile("..\\assets\\background.png"))
	{
		std::cerr << "ERROR: Unable to load window background texture!\n";
		exit(1);
	}

	window_bg.setTexture(window_bg_texture, true);
	window_bg.setTextureRect({ 0, 0, window_width, window_height });
	window_bg.setScale(1.5f, 1.5f);

	blocks.reserve(80);

	for (std::size_t i{}; i < 8; ++i)
	{
		for (std::size_t j{}; j < 10; ++j)
		{
			blocks.emplace_back(std::make_unique<Block>(static_cast<BlockColor>(i),
					(j * Block::width) + Block::width / 2,
					(i * Block::height) + Block::height / 2));
		}
	}
}

void Game::update()
{
	paddle.update();
	ball.update();
	paddle_collider.checkForCollision();
	block_collider.checkForCollision();

	window.draw(window_bg);
	window.draw(ball);
	window.draw(paddle);

	for (const auto& block : blocks)
		window.draw(*block);
}
