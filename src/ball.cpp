//
// Created by kszap on 26.09.2020.
//

#include <random>

#include "ball.hpp"
#include "game.hpp"

/**
 * @brief Ball constructor.
 * @param init_x Initial position in X-axis (default: 240.0f).
 * @param init_y Initial position in Y-axis (default: 350.0f).
 */
Ball::Ball(const float min_x, const float max_x, const float min_y, const float max_y)
		:min_x(min_x), max_x(max_x), min_y(min_y), max_y(max_y), velocity({ 5.5f, 5.5f })
{
	body = sf::CircleShape(12.0f);
	texture.loadFromFile("..\\assets\\objects.png");

	body.setTexture(&texture);
	body.setTextureRect(sf::IntRect(0.0f, 80.0f, 24.0f, 24.0f));
	body.setOrigin(12.0f, 12.0f);
	body.setPosition(randomizePosition(min_x, max_x, min_y, max_y));
}

sf::Vector2f Ball::randomizePosition(const float min_x, const float max_x, const float min_y, const float max_y)
{
	std::random_device rd;
	std::mt19937 mt(rd());

	std::uniform_real_distribution<float> dstrb_x(min_x, max_x);
	std::uniform_real_distribution<float> dstrb_y(min_y, max_y);

	return sf::Vector2f(dstrb_x(mt), dstrb_y(mt));
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
 * @brief Gets out_of_board flag value.
 * @return Boolean value whether ball is out of play area, or not.
 */
[[maybe_unused]] [[nodiscard]]
bool Ball::outOfBoard() const
{
	return out_of_board;
}

/**
 * @brief Ball's update method.
 *
 * Moves the ball accordingly to the velocity vector and
 * checks whether ball is in play area.
 * Collisions are controlled by individual colliders classes.
 */
void Ball::update()
{
	body.move(velocity);

	if (getDown() > Game::play_area_height - Paddle::body_height / 6)
	{
		out_of_board = true;
		velocity = { 0.0f, 0.0f };
	}
}

/**
 * @brief Bounces ball in X-axis when colliding with blocks.
 */
void Ball::bounceX()
{
	velocity.x *= -1;
}

/**
 * @brief Bounces ball in Y-axis when colliding with blocks.
 */
void Ball::bounceY()
{
	velocity.y *= -1;
}

/**
 * @brief Re-initializes ball position, velocity and out_of_board flag.
 * 	      Used when restaring game.
 * @param init_x Desired initial ball position in X-axis (default: 240.0f).
 * @param init_y Desired initial ball position in Y-axis (default: 350.0f).
 */
void Ball::reInitialize()
{
	body.setPosition(randomizePosition(min_x, max_x, min_y, max_y));
	out_of_board = false;
	velocity = { 5.5f, 5.5f };
}