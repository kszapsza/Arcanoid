//
// Created by kszap on 26.09.2020.
//

#pragma once

#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>

#include "assets_manager.hpp"
#include "ball.hpp"
#include "block.hpp"
#include "block_collider.hpp"
#include "levels_manager.hpp"
#include "message_box.hpp"
#include "paddle.hpp"
#include "paddle_collider.hpp"
#include "scoreboard.hpp"
#include "walls_collider.hpp"

#include <vector>

/**
 * @brief Enum describing possible game states. Boolean values such as
 * 	      game_over, game_won are not needed anymore.
 */
enum class GameState : std::uint8_t
{
	IN_PROGRESS = 0, GAME_OVER, GAME_WON, NEXT_LVL_DELAY
};

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

	GameState game_state;

	// COLLISSION CLASSES

	PaddleCollider paddle_collider{ assets, ball, paddle };
	BlockCollider block_collider{ assets, ball, levels_manager.blocks };
	WallsCollider walls_collider{ assets, ball, *this };

	// TEXTURES

	sf::Image icon;
	sf::Font karmatic_arcade;

	sf::Texture splashscreen_texture;
	sf::Texture window_bg_texture;

	sf::Texture level_completed_texture;
	sf::Texture game_over_texture;
	sf::Texture game_won_texture;

	// SPRITES

	sf::Sprite splashscreen;
	sf::Sprite window_bg;

	sf::Sprite level_completed_info;
	sf::Sprite game_over_info;
	sf::Sprite game_won_info;

	// USER INTERFACE

	Scoreboard scoreboard{ karmatic_arcade, window_width };
	MessageBox new_highscore{ karmatic_arcade };

	// SOUND BUFFERS AND SOUNDS

	sf::SoundBuffer game_over_sound_buffer;
	sf::SoundBuffer game_won_sound_buffer;

	sf::Sound game_over_sound;
	sf::Sound game_won_sound;

	// GAME DATA

	unsigned int previous_attempt_highscore{};

	unsigned int score{};
	unsigned int highscore{};

	unsigned int level{};

	// Needed to play game over/won sound effect only once in update() loop...
	bool game_result_sound_played{ false };

	void levelCompleted();
	void gameLost();

	void winLoseFreeze();
	void levelCompletedFreeze();

public:
	sf::RenderWindow window;

	[[maybe_unused]] static constexpr unsigned int window_width = 480;
	[[maybe_unused]] static constexpr unsigned int window_height = 780;

	[[maybe_unused]] static constexpr unsigned int play_area_width = 480;
	[[maybe_unused]] static constexpr unsigned int play_area_height = 700;

	Game();

	void setup();
	void showSplashscreen();

	void update();
};


