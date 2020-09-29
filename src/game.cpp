//
// Created by kszap on 26.09.2020.
//

#include "game.hpp"

#include <chrono>
#include <thread>

/**
 * @brief Main game class constructor.
 *
 * Sets window, window background, UI prompts textures
 * and properties, prepares gameboard etc.
 */
Game::Game()
		:window(sf::VideoMode(window_width, window_height),
		"Arcanoid", sf::Style::Close | sf::Style::Titlebar) // NOLINT(hicpp-signed-bitwise)
		, ball(20.0f, window_width - 20.0f, 360.0f, 500.0f)
{
	AssetsManager::tryLoad(icon, "..\\assets\\icon.png");

	window.setFramerateLimit(60u);
	window.setMouseCursorVisible(false);
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void Game::showSplashscreen()
{
	splashscreen_texture = assets.getTexture("..\\assets\\splashscreen.png");
	splashscreen_texture.setSmooth(false);
	splashscreen.setTexture(splashscreen_texture);

	window.draw(splashscreen);
	window.display();
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Game::setup()
{
	window_bg_texture = assets.getTexture("..\\assets\\background.png");
	window_bg_texture.setRepeated(true);

	window_bg.setTexture(window_bg_texture, true);
	window_bg.setTextureRect({ 0, 0, window_width, window_height });
	window_bg.setScale(1.5f, 1.5f);

	levels_manager.loadLevel(5);

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

	window.clear();
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
		walls_collider.checkForCollision();

		if (block_collider.checkForCollision())
		{
			score++;
			highscore = score > highscore ? score : highscore;
		}

		scoreboard.update(score, highscore);
	}

	window.draw(window_bg);
	window.draw(ball);
	window.draw(paddle);
	window.draw(scoreboard);

	for (const auto& block : levels_manager.blocks)
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

	if (levels_manager.blocks.empty())
	{
		game_won = true;
		window.draw(game_won_info);

		// Play sound only once after win.
		if (!game_result_sound_played)
			game_over_sound.play();

		game_result_sound_played = true;
	}

	if ((game_over || game_won) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		levels_manager.loadLevel(5);

		ball.reInitialize();
		paddle.reInitialize();

		game_over_sound.stop();
		game_won_sound.stop();

		score = 0;
		game_over = false;
		game_won = false;
		game_result_sound_played = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
	}
}