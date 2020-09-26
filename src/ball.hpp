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

	sf::Vector2f velocity{ 4.0f, 4.0f };
	bool out_of_board{};

public:
	explicit Ball(float init_x = 240.0f, float init_y = 350.0f);
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

	void reInitialize(float init_x = 256.0f, float init_y = 350.0f);
};


