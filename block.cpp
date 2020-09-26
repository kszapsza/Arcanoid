//
// Created by kszap on 26.09.2020.
//

#include "block.hpp"

Block::Block(AssetsManager& assets, const BlockColor color, const float init_x, const float init_y)
{
	body = sf::RectangleShape({ Block::width, Block::height });
	texture = assets.getTexture("..\\assets\\objects.png");

	body.setOrigin(Block::width / 2.0f, Block::height / 2.0f);
	body.setPosition(init_x, init_y);
	body.setTexture(&texture);

	switch (color)
	{
	case red:
		body.setTextureRect(sf::IntRect(72.0f, 0.0f, 64.0f, 32.0f));
		break;
	case orange:
		body.setTextureRect(sf::IntRect(0.0f, 0.0f, 64.0f, 32.0f));
		break;
	case yellow:
		body.setTextureRect(sf::IntRect(144.0f, 40.0f, 64.0f, 32.0f));
		break;
	case magenta:
		body.setTextureRect(sf::IntRect(0.0f, 40.0f, 64.0f, 32.0f));
		break;
	case pink:
		body.setTextureRect(sf::IntRect(216.0f, 40.0f, 64.0f, 32.0f));
		break;
	case green:
		body.setTextureRect(sf::IntRect(144.0f, 0.0f, 64.0f, 32.0f));
		break;
	case cyan:
		body.setTextureRect(sf::IntRect(72.0f, 40.0f, 64.0f, 32.0f));
		break;
	case purple:
		body.setTextureRect(sf::IntRect(216.0f, 0.0f, 64.0f, 32.0f));
		break;
	}
}

void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(body, states);
}

sf::FloatRect Block::getGlobalBounds() const
{
	return body.getGlobalBounds();
}


