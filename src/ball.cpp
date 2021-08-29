//
// Created by kszap on 26.09.2020.
//

#include <random>

#include "ball.hpp"
#include "game.hpp"

/**
 * @brief Ball constructor.
 * @param maxX Maximum x position to randomize..
 * @param minX Minimum x position to randomize..
 * @param maxY Maximum y position to randomize..
 * @param minY Minimum y position to randomize.
 */
Ball::Ball(const float minX, const float maxX, const float minY, const float maxY)
		: minX(minX), maxX(maxX), minY(minY), maxY(maxY)
{
	body = sf::CircleShape(12.0f);
	texture.loadFromFile("..\\assets\\objects.png");

	body.setTexture(&texture);
	body.setTextureRect(sf::IntRect(0.0f, 80.0f, 24.0f, 24.0f));
	body.setOrigin(12.0f, 12.0f);
	body.setPosition(randomizePosition(minX, maxX, minY, maxY));
}

sf::Vector2f Ball::randomizePosition(const float minX, const float maxX, const float minY, const float maxY)
{
	std::random_device rd;
	std::mt19937 mt(rd());

	std::uniform_real_distribution<float> distributionX(minX, maxX);
	std::uniform_real_distribution<float> distributionY(minY, maxY);

	return { distributionX(mt), distributionY(mt) };
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
 * @brief Gets outOfBoard flag value.
 * @return Boolean value whether ball is out of play area, or not.
 */
[[maybe_unused]] [[nodiscard]]
bool Ball::isOutOfBoard() const
{
	return outOfBoard;
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

	if (getDown() > Game::PLAY_AREA_HEIGHT - Paddle::BODY_HEIGHT / 6)
	{
		outOfBoard = true;
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
 * @brief Re-initializes ball position, velocity and outOfBoard flag.
 * 	      Used when restarting game.
 * @param init_x Desired initial ball position in X-axis (default: 240.0f).
 * @param init_y Desired initial ball position in Y-axis (default: 350.0f).
 */
void Ball::reInitialize()
{
	body.setPosition(randomizePosition(minX, maxX, minY, maxY));
	outOfBoard = false;
	velocity = { INITIAL_VELOCITY_X, INITIAL_VELOCITY_Y };
}