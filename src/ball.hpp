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
 * on the board (bouncing around), sets out_of_board flag, which is further
 * used to detect game over conditions, bounces the ball against board borders.
 */

class Ball : public sf::Drawable
{
private:
	sf::CircleShape body{};
	sf::Texture texture{};

	const float min_x, max_x, min_y, max_y;

	static constexpr float init_x_velocity = 2.5f;
	static constexpr float init_y_velocity = 2.5f;
	sf::Vector2f velocity{ init_x_velocity, init_y_velocity };

	bool out_of_board{ false };

	static sf::Vector2f randomizePosition(float min_x, float max_x, float min_y, float max_y);

public:
	explicit Ball(float min_x, float max_x, float min_y, float max_y);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	[[maybe_unused]] [[nodiscard]] float bodyRadius() const;
	[[maybe_unused]] [[nodiscard]] const sf::Vector2f& getPosition() const;
	[[maybe_unused]] [[nodiscard]] float getUp() const;
	[[maybe_unused]] [[nodiscard]] float getLeft() const;
	[[maybe_unused]] [[nodiscard]] float getDown() const;
	[[maybe_unused]] [[nodiscard]] float getRight() const;
	[[maybe_unused]] [[nodiscard]] sf::FloatRect getGlobalBounds() const;
	[[maybe_unused]] [[nodiscard]] bool outOfBoard() const;

	void update();

	void bounceX();

	void bounceY();

	void reInitialize();
};


