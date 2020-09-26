//
// Created by kszap on 26.09.2020.
//

#pragma once

#include <SFML\Graphics.hpp>

/**
 * @brief Drawable, movable paddle object.
 *
 * Stores paddle data such as shape, texture, moving delta (offset).
 * Creates an interface to control the object position with keyboard.
 * Contains variety of getters to retrieve paddle's body position.
 */

class Paddle : public sf::Drawable
{
private:
	sf::RectangleShape body{};
	sf::Texture texture{};

	const float move_offset{ 5.0f };

	void moveLeft();
	void moveRight();

public:
	Paddle();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	[[maybe_unused]] [[nodiscard]] float bodyWidth() const;
	[[maybe_unused]] [[nodiscard]] float bodyHeight() const;

	[[maybe_unused]] [[nodiscard]] const sf::Vector2f& getPosition() const;
	[[maybe_unused]] [[nodiscard]] float getUp() const;
	[[maybe_unused]] [[nodiscard]] float getLeft() const;
	[[maybe_unused]] [[nodiscard]] float getDown() const;
	[[maybe_unused]] [[nodiscard]] float getRight() const;
	[[maybe_unused]] [[nodiscard]] sf::FloatRect getGlobalBounds() const;

	void update();
	void reInitialize(float init_x = 256.0f, float init_y = 688.0f);
};

