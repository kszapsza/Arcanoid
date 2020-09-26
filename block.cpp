//
// Created by kszap on 26.09.2020.
//

#include "block.hpp"

Block::Block(const BlockColor color, const float init_x, const float init_y)
{
	body = sf::RectangleShape({64.0f, 32.0f});
	texture.loadFromFile("..\\assets\\objects.png");

	body.setOrigin(32.0f, 16.0f);
	body.setPosition(init_x, init_y);
	body.setTexture(&texture);

	switch (color)
	{
	case red:
		body.setTextureRect(sf::IntRect(72.0f, 0.0f, Block::width, Block::height));
		break;
	case orange:
		body.setTextureRect(sf::IntRect(0.0f, 0.0f, Block::width, Block::height));
		break;
	case yellow:
		body.setTextureRect(sf::IntRect(144.0f, 40.0f, Block::width, Block::height));
		break;
	case magenta:
		body.setTextureRect(sf::IntRect(0.0f, 40.0f, Block::width, Block::height));
		break;
	case pink:
		body.setTextureRect(sf::IntRect(216.0f, 40.0f, Block::width, Block::height));
		break;
	case green:
		body.setTextureRect(sf::IntRect(144.0f, 0.0f, Block::width, Block::height));
		break;
	case cyan:
		body.setTextureRect(sf::IntRect(72.0f, 40.0f, Block::width, Block::height));
		break;
	case purple:
		body.setTextureRect(sf::IntRect(216.0f, 0.0f, Block::width, Block::height));
		break;
	}
}

void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(body, states);
}


