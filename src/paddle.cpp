//
// Created by kszap on 26.09.2020.
//

#include "paddle.hpp"

/**
 * @brief Paddle constructor. Initializes shape, texture, position etc.
 */
Paddle::Paddle()
{
	body = sf::RectangleShape({ 96.0f, 24.0f });
	texture.loadFromFile("..\\assets\\objects.png");

	body.setTexture(&texture);
	body.setTextureRect(sf::IntRect(184.0f, 112.0f, 96.0f, 24.0f));
	body.setOrigin(48.0f, 12.0f);
	body.setPosition(256.0f, 688.0f);
}

/**
 * @brief Moves paddle to the left (taking into account play area).
 */
void Paddle::moveLeft()
{
	if (getLeft() > 0)
		body.move(-move_offset, 0.0f);
}

/**
 * @brief Moves paddle to the right (taking into account play area).
 */
void Paddle::moveRight()
{
	if (getRight() < 480)
		body.move(move_offset, 0.0f);
}

/**
 * @brief sf::Drawable's draw() method override. Draws the object to a render target.
 * @param target Render target to draw to.
 * @param states Current render states.
 */
void Paddle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(body, states);
}

/**
 * @brief Returns sf::Vector2f representing current paddle position.
 * @return Paddle position in sf::Vector2f form.
 */
[[maybe_unused]] [[nodiscard]]
const sf::Vector2f& Paddle::getPosition() const
{
	return body.getPosition();
}

/**
 * @brief Gets upper bound of paddle's body.
 * @return Upper bound coordinate in Y axis.
 */
[[maybe_unused]] [[nodiscard]]
float Paddle::getUp() const
{
	return body.getPosition().y + Paddle::body_height / 2;
}

/**
 * @brief Gets left bound of paddle's body.
 * @return Left bound coordinate in X axis.
 */
[[maybe_unused]] [[nodiscard]]
float Paddle::getLeft() const
{
	return body.getPosition().x - Paddle::body_width / 2;
}

/**
 * @brief Gets down bound of paddle's body.
 * @return Down bound coordinate in Y axis.
 */
[[maybe_unused]] [[nodiscard]]
float Paddle::getDown() const
{
	return body.getPosition().y - Paddle::body_height / 2;
}

/**
 * @brief Gets right bound of paddle's body.
 * @return Right bound coordinate in X axis.
 */
[[maybe_unused]] [[nodiscard]]
float Paddle::getRight() const
{
	return body.getPosition().x + Paddle::body_width / 2;
}

/**
 * @brief Gets global bounds of paddle's body.
 * @return Ball's body global bounds in the form of sf::FloatRect.
 */
[[maybe_unused]] [[nodiscard]]
sf::FloatRect Paddle::getGlobalBounds() const
{
	return body.getGlobalBounds();
}

/**
 * @brief Paddle's update method.
 *
 * Moves the paddle when [A]/[D] or [<-]/[->] are pressed.
 * Calls moveLeft/Right methods which ensure if movement is possible
 * in the play area restrictions.
 */
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

/**
 * @brief Re-initializes paddle position.
 * @param init_x Desired initial ball position in X-axis (default: 256.0f).
 * @param init_y Desired initial ball position in Y-axis (default: 688.0f).
 */
void Paddle::reInitialize(const float init_x, const float init_y)
{
	body.setPosition(init_x, init_y);
}