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
 * This class initializes and handles game window, assets manager
 * and all essential game elements, such as: ball, paddle,
 * vector of blocks pointers, necessary texture references,
 * collision classes and game over/won booleans.
 */
class Game
{
private:
	AssetsManager assets;

	Ball ball;
	Paddle paddle;

	LevelsManager levelsManager{ assets };

	GameState gameState;

	// COLLISION CLASSES

	PaddleCollider paddleCollider{ assets, ball, paddle };
	BlockCollider blockCollider{ assets, ball, levelsManager.blocks };
	WallsCollider wallsCollider{ assets, ball, *this };

	// TEXTURES

	sf::Image icon;
	sf::Font karmaticArcade;

	sf::Texture splashscreenTexture;
	sf::Texture windowBackgroundTexture;

	sf::Texture levelCompletedTexture;
	sf::Texture gameOverTexture;
	sf::Texture gameWonTexture;

	// SPRITES

	sf::Sprite splashscreen;
	sf::Sprite windowBackground;

	sf::Sprite levelCompletedInfo;
	sf::Sprite gameOverInfo;
	sf::Sprite gameWonInfo;

	// USER INTERFACE

	Scoreboard scoreboard{ karmaticArcade, WINDOW_WIDTH };
	MessageBox newHighscore{ karmaticArcade };

	// SOUND BUFFERS AND SOUNDS

	sf::SoundBuffer gameOverSoundBuffer;
	sf::SoundBuffer gameWonSoundBuffer;

	sf::Sound gameOverSound;
	sf::Sound gameWonSound;

	// GAME DATA

	unsigned int previousAttemptHighscore{};

	unsigned int score{};
	unsigned int highscore{};

	unsigned int level{};

	// Needed to play game over/won sound effect only once in update() loop...
	bool gameResultSoundPlayed{ false };

	void levelCompleted();
	void gameLost();

	void winLoseFreeze();
	void levelCompletedFreeze();

public:
	sf::RenderWindow window;

	[[maybe_unused]] static constexpr unsigned int WINDOW_WIDTH = 480;
	[[maybe_unused]] static constexpr unsigned int WINDOW_HEIGHT = 780;

	[[maybe_unused]] static constexpr unsigned int PLAY_AREA_WIDTH = 480;
	[[maybe_unused]] static constexpr unsigned int PLAY_AREA_HEIGHT = 700;

	Game();

	void setup();
	void showSplashscreen();

	void update();
};


