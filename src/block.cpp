//
// Created by kszap on 26.09.2020.
//

#include "block.hpp"

/**
 * @brief Block constructor.
 * @param assets An instance of AssetsManager, holding textures. Allows to load textures only once.
 * @param color BlockColor enumerable type describing desired block color.
 * @param initX Initial position in X-axis.
 * @param initY Initial position in Y-axis.
 */
Block::Block(AssetsManager& assets, const BlockColor color, const float initX, const float initY)
{
	body = sf::RectangleShape({ Block::width, Block::height });
	texture = assets.getTexture("..\\assets\\objects.png");

	body.setOrigin(Block::width / 2.0f, Block::height / 2.0f);
	body.setPosition(initX, initY);
	body.setTexture(&texture);

	switch (color)
	{
	case RED:
		body.setTextureRect(sf::IntRect(72.0f, 0.0f, 64.0f, 32.0f));
		break;
	case ORANGE:
		body.setTextureRect(sf::IntRect(0.0f, 0.0f, 64.0f, 32.0f));
		break;
	case YELLOW:
		body.setTextureRect(sf::IntRect(144.0f, 40.0f, 64.0f, 32.0f));
		break;
	case MAGENTA:
		body.setTextureRect(sf::IntRect(0.0f, 40.0f, 64.0f, 32.0f));
		break;
	case PINK:
		body.setTextureRect(sf::IntRect(216.0f, 40.0f, 64.0f, 32.0f));
		break;
	case GREEN:
		body.setTextureRect(sf::IntRect(144.0f, 0.0f, 64.0f, 32.0f));
		break;
	case CYAN:
		body.setTextureRect(sf::IntRect(72.0f, 40.0f, 64.0f, 32.0f));
		break;
	case PURPLE:
		body.setTextureRect(sf::IntRect(216.0f, 0.0f, 64.0f, 32.0f));
		break;
	}
}

/**
 * @brief sf::Drawable's draw() method override. Draws the object to a render target.
 * @param target Render target to draw to.
 * @param states Current render states.
 */
void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(body, states);
}

/**
 * @brief Gets global bounds of ball's body.
 * @return Ball's body global bounds in the form of sf::FloatRect.
 */
sf::FloatRect Block::getGlobalBounds() const
{
	return body.getGlobalBounds();
}


