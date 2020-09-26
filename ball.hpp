//
// Created by kszap on 26.09.2020.
//

#pragma once

#include <SFML\Graphics.hpp>

class Ball : public sf::Drawable
{
private:
	sf::CircleShape body{};
	sf::Texture texture{};

	sf::Vector2f velocity{ 4.0f, 4.0f };

	bool out_of_board{};

public:
	explicit Ball(float init_x = 256.0f, float init_y = 350.0f);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	float bodyRadius() const;

	const sf::Vector2f& getPosition() const;
	float getUp() const;
	float getLeft() const;
	float getDown() const;
	float getRight() const;
	sf::FloatRect getGlobalBounds() const;

	void update();
	void bounce();
	bool outOfBoard();

	void reInitialize(float init_x = 256.0f, float init_y = 350.0f);
};


