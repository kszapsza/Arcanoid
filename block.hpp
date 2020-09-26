//
// Created by kszap on 26.09.2020.
//

#pragma once

#include <SFML\Graphics.hpp>

enum BlockColor : std::uint8_t
{
	red = 0, orange = 1, yellow = 2, magenta = 3,
	pink = 4, green = 5, cyan = 6, purple = 7
};

class Block : public sf::Drawable
{
private:
	sf::RectangleShape body{};
	sf::Texture texture{};

public:
	static constexpr float width = 48.0f;
	static constexpr float height = 24.0f;

	explicit Block(BlockColor color, float init_x, float init_y);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::FloatRect getGlobalBounds() const;
};