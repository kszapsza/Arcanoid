//
// Created by kszap on 26.09.2020.
//

#include "paddle.hpp"

Paddle::Paddle()
{
	body = sf::RectangleShape({ 96.0f, 24.0f });
	texture.loadFromFile("..\\assets\\objects.png");

	body.setTexture(&texture);
	body.setTextureRect(sf::IntRect(184.0f, 112.0f, 96.0f, 24.0f));
	body.setOrigin(48.0f, 12.0f);
	body.setPosition(256.0f, 688.0f);
}

void Paddle::moveLeft()
{
	if (getLeft() > 0)
		body.move(-move_offset, 0.0f);
}

void Paddle::moveRight()
{
	if (getRight() < 480)
		body.move(move_offset, 0.0f);
}

void Paddle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(body, states);
}

float Paddle::bodyWidth() const
{
	return body.getLocalBounds().width;
}

float Paddle::bodyHeight() const
{
	return body.getLocalBounds().height;
}

const sf::Vector2f& Paddle::getPosition() const
{
	return body.getPosition();
}

float Paddle::getUp() const
{
	return body.getPosition().y + bodyHeight() / 2;
}

float Paddle::getLeft() const
{
	return body.getPosition().x - bodyWidth() / 2;
}

float Paddle::getDown() const
{
	return body.getPosition().y - bodyHeight() / 2;
}

float Paddle::getRight() const
{
	return body.getPosition().x + bodyWidth() / 2;
}

sf::FloatRect Paddle::getGlobalBounds() const
{
	return body.getGlobalBounds();
}

void Paddle::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		moveLeft();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		moveRight();
	}
}

void Paddle::reInitialize(const float init_x, const float init_y)
{
	body.setPosition(init_x, init_y);
}