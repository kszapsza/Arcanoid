//
// Created by kszap on 26.09.2020.
//

#pragma once

#include <SFML\Graphics.hpp>

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

	float bodyWidth() const;
	float bodyHeight() const;

	const sf::Vector2f& getPosition() const;
	float getUp() const;
	float getLeft() const;
	float getDown() const;
	float getRight() const;
	sf::FloatRect getGlobalBounds() const;

	void update();
	void reInitialize(float init_x = 256.0f, float init_y = 688.0f);
};

