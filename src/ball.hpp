//
// Created by kszap on 26.09.2020.
//

#pragma once

#include <SFML\Graphics.hpp>

/**
 * @brief Drawable ball object.
 *
 * Stores necessary ball data: shape, texture, velocity, is ball on board.
 * Creates full-fledged interface to control the object with position/size
 * getters and more importantly an update method, controlling ball's movement
 * on the board (bouncing around), sets outOfBoard flag, which is further
 * used to detect game over conditions, bounces the ball against board borders.
 */

class Ball : public sf::Drawable
{
private:
	sf::CircleShape body{};
	sf::Texture texture{};

	const float minX, maxX, minY, maxY;

	static constexpr float INITIAL_VELOCITY_X = 4.5f;
	static constexpr float INITIAL_VELOCITY_Y = 4.5f;

	sf::Vector2f velocity{ INITIAL_VELOCITY_X, INITIAL_VELOCITY_Y };

	bool outOfBoard{ false };

	static sf::Vector2f randomizePosition(float minX, float maxX, float minY, float maxY);

public:
	explicit Ball(float minX, float maxX, float minY, float maxY);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	[[maybe_unused]] [[nodiscard]] float bodyRadius() const;
	[[maybe_unused]] [[nodiscard]] const sf::Vector2f& getPosition() const;
	[[maybe_unused]] [[nodiscard]] float getUp() const;
	[[maybe_unused]] [[nodiscard]] float getLeft() const;
	[[maybe_unused]] [[nodiscard]] float getDown() const;
	[[maybe_unused]] [[nodiscard]] float getRight() const;
	[[maybe_unused]] [[nodiscard]] sf::FloatRect getGlobalBounds() const;
	[[maybe_unused]] [[nodiscard]] bool isOutOfBoard() const;

	void update();
	void bounceX();
	void bounceY();
	void reInitialize();
};


