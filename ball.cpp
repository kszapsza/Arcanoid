//
// Created by kszap on 26.09.2020.
//

#include "ball.hpp"

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

void Ball::update()
{
	body.move(velocity);

	if (getLeft() < 0 || getRight() > 512)
		velocity.x *= -1;

	if (getUp() < 0 || getDown() > 700)
		velocity.y *= -1;
}