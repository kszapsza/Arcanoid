//
// Created by kszap on 26.09.2020.
//

#include "ball.hpp"
#include <iostream>

Ball::Ball(const float init_x, const float init_y)
{
	body = sf::CircleShape(12.0f);
	texture.loadFromFile("..\\assets\\objects.png");

	body.setTexture(&texture);
	body.setTextureRect(sf::IntRect(0.0f, 80.0f, 24.0f, 24.0f));
	body.setOrigin(12.0f, 12.0f);
	body.setPosition(init_x, init_y);
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(body, states);
}

float Ball::bodyRadius() const
{
	return body.getRadius();
}

const sf::Vector2f& Ball::getPosition() const
{
	return body.getPosition();
}

float Ball::getUp() const
{
	return body.getPosition().y - body.getRadius();
}

float Ball::getLeft() const
{
	return body.getPosition().x - body.getRadius();
}

float Ball::getDown() const
{
	return body.getPosition().y + body.getRadius();
}

float Ball::getRight() const
{
	return body.getPosition().x + body.getRadius();
}

sf::FloatRect Ball::getGlobalBounds() const
{
	return body.getGlobalBounds();
}

void Ball::update()
{
	body.move(velocity);

	if (getLeft() < 0 || getRight() > 480)
		velocity.x *= -1;

	if (getUp() < 0)
		velocity.y *= -1;

	if (getDown() > 700)
	{
		out_of_board = true;
		velocity = { 0.0f, 0.0f };
	}
}

void Ball::bounce()
{
	velocity.y *= -1;
}

bool Ball::outOfBoard()
{
	return out_of_board;
}

void Ball::reInitialize(const float init_x, const float init_y)
{
	body.setPosition(init_x, init_y);
	out_of_board = false;
	velocity = { 4.0f, 4.0f };
}