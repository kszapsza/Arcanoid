//
// Created by kszap on 26.09.2020.
//

#include "game.hpp"

// Debug cheats switch
#define DEBUG_CHEATS 1

/**
 * @brief Main game class constructor.
 *
 * Sets window, window background, UI prompts textures
 * and properties, prepares gameboard etc.
 */
Game::Game()
		: window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		"Arcanoid", sf::Style::Close | sf::Style::Titlebar) // NOLINT(hicpp-signed-bitwise)
		, ball(20.0f, WINDOW_WIDTH - 20.0f, 360.0f, 500.0f), gameState(GameState::IN_PROGRESS)
{
	AssetsManager::tryLoad(icon, "..\\assets\\icon.png");

	window.setFramerateLimit(60u);
	window.setMouseCursorVisible(false);
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void Game::showSplashscreen()
{
	splashscreenTexture = assets.getTexture("..\\assets\\splashscreen.png");
	splashscreenTexture.setSmooth(false);
	splashscreen.setTexture(splashscreenTexture);

	window.draw(splashscreen);
	window.display();
	sf::sleep(sf::milliseconds(1500));
}

void Game::setup()
{
	karmaticArcade = assets.getFont("..\\assets\\karmatic_arcade.ttf");

	// UI messages content assigment.
	newHighscore.setString("NEW HIGHSCORE ACHIEVED");

	windowBackgroundTexture = assets.getTexture("..\\assets\\background.png");
	windowBackgroundTexture.setRepeated(true);

	windowBackground.setTexture(windowBackgroundTexture, true);
	windowBackground.setTextureRect({ 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT });
	windowBackground.setScale(1.5f, 1.5f);

	levelsManager.loadLevel(level);

	// TEXTURES

	levelCompletedTexture = assets.getTexture("..\\assets\\level_completed.png");
	levelCompletedTexture.setSmooth(false);

	gameOverTexture = assets.getTexture("..\\assets\\game_over.png");
	gameOverTexture.setSmooth(false);

	gameWonTexture = assets.getTexture("..\\assets\\game_won.png");
	gameWonTexture.setSmooth(false);

	// SPRITES

	levelCompletedInfo.setTexture(levelCompletedTexture);
	levelCompletedInfo.setPosition(0.0f, 250.0f);

	gameOverInfo.setTexture(gameOverTexture);
	gameOverInfo.setPosition(0.0f, 250.0f);

	gameWonInfo.setTexture(gameWonTexture);
	gameWonInfo.setPosition(0.0f, 250.0f);

	// SOUNDS

	gameOverSoundBuffer = assets.getSound("..\\assets\\game_over.wav");
	gameOverSound.setBuffer(gameOverSoundBuffer);

	gameWonSoundBuffer = assets.getSound("..\\assets\\game_won.wav");
	gameWonSound.setBuffer(gameWonSoundBuffer);

	window.clear();
}

/**
 * @brief Main game update method. Checks win/lose conditions,
 * draws essential objects, shows UI screens, restarts game etc.
 */
void Game::update()
{
	// UPDATING OBJECTS

	if (gameState == GameState::IN_PROGRESS)
	{
		paddle.update();
		ball.update();

		paddleCollider.checkForCollision();
		wallsCollider.checkForCollision();

		if (blockCollider.checkForCollision())
		{
			score++;
			highscore = score > highscore ? score : highscore;
		}

		scoreboard.update(score, highscore);
	}

#if DEBUG_CHEATS == 1
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F10))
	{
		levelsManager.blocks.clear();
	}
#endif

	window.draw(windowBackground);
	window.draw(ball);
	window.draw(paddle);
	window.draw(scoreboard);

	for (const auto& block: levelsManager.blocks)
	{
		window.draw(*block);
	}

	// ENDING SCENARIOS

	if (ball.isOutOfBoard())
	{
		gameLost();
	}

	if (levelsManager.blocks.empty())
	{
		levelCompleted();
	}

	// RAGE QUIT

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
	}
}

/**
 * @brief Method called if no blocks are present in the play area.
 * 		  If there are no next levels, displays winscreen.
 * 		  Otherwise, next level is loaded and started.
 */
void Game::levelCompleted()
{
	// Play sound only once.
	if (!gameResultSoundPlayed)
	{
		gameWonSound.play();
		gameResultSoundPlayed = true;
	}

	// Load next level, if exists.
	if (level + 1 < levelsManager.levelsAmount())
	{
		gameState = GameState::NEXT_LVL_DELAY;
		window.draw(levelCompletedInfo);

		levelCompletedFreeze();
	}
		// Otherwise, player wins.
	else
	{
		gameState = GameState::GAME_WON;
		window.draw(gameWonInfo);

		winLoseFreeze();
	}
}

void Game::gameLost()
{
	gameState = GameState::GAME_OVER;

	// Play sound only once.
	if (!gameResultSoundPlayed)
	{
		gameOverSound.play();
		gameResultSoundPlayed = true;
	}

	window.draw(gameOverInfo);

	if (highscore > previousAttemptHighscore)
	{
		window.draw(newHighscore);
	}

	winLoseFreeze();
}

void Game::winLoseFreeze()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		// Reset current score and level...
		score = 0;
		level = 0;

		// Game results flags...
		gameState = GameState::IN_PROGRESS;
		gameResultSoundPlayed = false;

		previousAttemptHighscore = (highscore > previousAttemptHighscore) ?
								   highscore : previousAttemptHighscore;

		levelsManager.loadLevel(0);

		ball.reInitialize();
		paddle.reInitialize();

		gameOverSound.stop();
		gameWonSound.stop();
	}
}

/**
 * @brief Screen shown before loading next level. Call if and only if there are
 * 		  further levels avaiable! Waits for players space press and loads next level.
 */
void Game::levelCompletedFreeze()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		level++;
		levelsManager.loadLevel(level);

		gameState = GameState::IN_PROGRESS;

		ball.reInitialize();
		paddle.reInitialize();

		gameResultSoundPlayed = false;
		gameWonSound.stop();
	}
}