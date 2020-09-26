//
// Created by kszap on 26.09.2020.
//

#include "ball.hpp"

/**
 * @brief Ball constructor.
 * @param init_x Initial position in X-axis (default: 240.0f).
 * @param init_y Initial position in Y-axis (default: 350.0f).
 */
Ball::Ball(const float init_x, const float init_y)
{
	body = sf::CircleShape(12.0f);
	texture.loadFromFile("..\\assets\\objects.png");

	body.setTexture(&texture);
	body.setTextureRect(sf::IntRect(0.0f, 80.0f, 24.0f, 24.0f));
	body.setOrigin(12.0f, 12.0f);
	body.setPosition(init_x, init_y);
}

/**
 * @brief sf::Drawable's draw() method override. Draws the object to a render target.
 * @param target Render target to draw to.
 * @param states Current render states.
 */
void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(body, states);
}

/**
 * @brief Returns radius of the ball body.
 * @return Radius of the ball body.
 */
[[maybe_unused]] [[nodiscard]]
float Ball::bodyRadius() const
{
	return body.getRadius();
}

/**
 * @brief Returns sf::Vector2f representing current ball position.
 * @return Ball position in sf::Vector2f form.
 */
[[maybe_unused]] [[nodiscard]]
const sf::Vector2f& Ball::getPosition() const
{
	return body.getPosition();
}

/**
 * @brief Gets upper bound of ball's body.
 * @return Upper bound coordinate in Y axis.
 */
[[maybe_unused]] [[nodiscard]]
float Ball::getUp() const
{
	return body.getPosition().y - body.getRadius();
}

/**
 * @brief Gets left bound of ball's body.
 * @return Left bound coordinate in X axis.
 */
[[maybe_unused]] [[nodiscard]]
float Ball::getLeft() const
{
	return body.getPosition().x - body.getRadius();
}

/**
 * @brief Gets down bound of ball's body.
 * @return Down bound coordinate in Y axis.
 */
[[maybe_unused]] [[nodiscard]]
float Ball::getDown() const
{
	return body.getPosition().y + body.getRadius();
}

/**
 * @brief Gets right bound of ball's body.
 * @return Right bound coordinate in X axis.
 */
[[maybe_unused]] [[nodiscard]]
float Ball::getRight() const
{
	return body.getPosition().x + body.getRadius();
}

/**
 * @brief Gets global bounds of ball's body.
 * @return Ball's body global bounds in the form of sf::FloatRect.
 */
[[maybe_unused]] [[nodiscard]]
sf::FloatRect Ball::getGlobalBounds() const
{
	return body.getGlobalBounds();
}

/**
 * @brief Ball's update method.
 *
 * Moves the ball accordingly to the velocity vector, changes
 * the movement direction when bouncing off the walls, stops
 * the ball and sets appropriate flag if it collided with lower
 * border of the board.
 */
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

/**
 * @brief Bounces ball in Yaxis when colliding with blocks.
 */
void Ball::bounce()
{
	velocity.y *= -1;
}

/**
 * @brief Gets out_of_board flag value.
 * @return Boolean value whether ball is out of play area, or not.
 */
bool Ball::outOfBoard()
{
	return out_of_board;
}

/**
 * @brief Re-initializes ball position, velocity and out_of_board flag.
 * 	      Used when restaring game.
 * @param init_x Desired initial ball position in X-axis (default: 240.0f).
 * @param init_y Desired initial ball position in Y-axis (default: 350.0f).
 */
void Ball::reInitialize(const float init_x, const float init_y)
{
	body.setPosition(init_x, init_y);
	out_of_board = false;
	velocity = { 4.0f, 4.0f };
}