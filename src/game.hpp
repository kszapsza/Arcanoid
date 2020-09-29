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
#include "levels_manager.hpp"
#include "paddle.hpp"
#include "paddle_collider.hpp"
#include "scoreboard.hpp"
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

	LevelsManager levels_manager{ assets };
	Scoreboard scoreboard{ assets, window_width };

	// COLLISSION CLASSES

	PaddleCollider paddle_collider{ assets, ball, paddle };
	BlockCollider block_collider{ assets, ball, levels_manager.blocks };
	WallsCollider walls_collider{ assets, ball, *this };

	// TEXTURES & SPRITES

	sf::Image icon;

	sf::Texture splashscreen_texture;
	sf::Texture window_bg_texture;
	sf::Texture game_over_texture;
	sf::Texture game_won_texture;

	sf::Sprite splashscreen;
	sf::Sprite window_bg;
	sf::Sprite game_over_info;
	sf::Sprite game_won_info;

	// SOUND BUFFERS AND SOUNDS

	sf::SoundBuffer game_over_sound_buffer;
	sf::SoundBuffer game_won_sound_buffer;

	sf::Sound game_over_sound;
	sf::Sound game_won_sound;

	// GAME DATA

	unsigned int score{};
	unsigned int highscore{};

	bool game_over{ false };
	bool game_won{ false };

	// Needed to play game over/won sound effect only once in update() loop...
	bool game_result_sound_played{ false };

public:
	[[maybe_unused]] static constexpr unsigned int window_width = 480;
	[[maybe_unused]] static constexpr unsigned int window_height = 780;

	[[maybe_unused]] static constexpr unsigned int play_area_width = 480;
	[[maybe_unused]] static constexpr unsigned int play_area_height = 700;

	sf::RenderWindow window;

	Game();

	void setup();
	void showSplashscreen();

	void update();
};


