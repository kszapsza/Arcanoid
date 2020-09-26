#include <SFML/Graphics.hpp>
#include <iostream>

#include "ball.hpp"
#include "paddle.hpp"

constexpr unsigned int window_width = 512;
constexpr unsigned int window_height = 700;

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
 */

int main()
{
	sf::RenderWindow window{ sf::VideoMode(window_width, window_height),
			"Arcanoid", sf::Style::Close | sf::Style::Titlebar };
	window.setFramerateLimit(60u);

	sf::Texture window_bg_texture;
	window_bg_texture.setRepeated(true);

	if (!window_bg_texture.loadFromFile("..\\assets\\background.png"))
	{
		std::cerr << "ERROR: Unable to load window background texture!\n";
		exit(1);
	}

	sf::Sprite window_bg;
	window_bg.setTexture(window_bg_texture, true);
	window_bg.setTextureRect({0, 0, window_width, window_height});
	window_bg.setScale(1.5f, 1.5f);

	Ball ball{ 256.0f, 350.0f };
	Paddle paddle{};

	while (window.isOpen())
	{
		sf::Event evnt{};
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Blue);

		paddle.update();
		ball.update();

		window.draw(window_bg);
		window.draw(ball);
		window.draw(paddle);

		window.display();
	}
}
