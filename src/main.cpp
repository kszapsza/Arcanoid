#include <SFML/Graphics.hpp>

#include "block.hpp"
#include "block_collider.hpp"
#include "game.hpp"

/**
 * SFML Arcanoid-like pixel 2D game.
 * (C) 2020 Karol Szapsza
 *
 * @title Arcanoid
 * @date 2020
 * @author Karol Szapsza
 *
 * In order to run the game successfully, including SFML's DLLs in
 * executable's directory seems required (see \dlls\ directory)
 *
 * background.png :: https://noobtuts.com/unity/2d-arkanoid-game
 * LICENSE:		public domain
 * DISCLAIMER:	This image consists only of simple geometric shapes or text.
 * 				It does not meet the threshold of originality needed for
 * 				copyright protection, and is therefore in the public domain.
 * 				Although it is free of copyright restrictions, this image
 * 				may still be subject to other restrictions.
 *
 * objects.png
 * SOURCE:		https://opengameart.org/content/basic-arkanoid-pack
 * AUTHOR:		Zealex
 * LICENSE:		Attribution 3.0 Unported (CC BY 3.0)
 *
 * Karmatic Arcade font, in game_over.png, game_won.png, banner.png etc.:
 * SOURCE:		https://www.1001fonts.com/karmatic-arcade-font.html
 * LICENSE: 	1001Fonts Free For Commercial Use License (FFC)
 *
 * 8-bit sound effects library:
 * SOURCE:		https://freesound.org/people/LittleRobotSoundFactory/
 * AUTHOR:		LittleRobotSoundFactory
 * LICENSE:		Attribution 3.0 Unported (CC BY 3.0)
 */

int main()
{
	Game game{};

	game.showSplashscreen();
	game.setup();

	while (game.window.isOpen())
	{
		sf::Event evnt{};

		while (game.window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				game.window.close();
		}

		game.window.clear(sf::Color::Black);
		game.update();
		game.window.display();
	}
}
