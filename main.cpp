#include <SFML/Graphics.hpp>

#include "block.hpp"
#include "block_collider.hpp"
#include "game.hpp"

/*
 * SFML Arcanoid-like pixel 2D game.
 * (C) 2020 Karol Szapsza
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
 * In order to run the game successfully, including SFML's DLLs in
 * executable's directory seems required.
 */

int main()
{
	Game game{};

	while (game.window.isOpen())
	{
		sf::Event evnt{};

		while (game.window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				game.window.close();
		}

		game.window.clear(sf::Color::Blue);
		game.update();
		game.window.display();
	}
}
