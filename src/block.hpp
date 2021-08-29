//
// Created by kszap on 26.09.2020.
//

#pragma once

#include <SFML\Graphics.hpp>
#include "assets_manager.hpp"

/**
 * @brief Enumeration type storing possible block colors.
 */

enum BlockColor : std::uint8_t
{
	RED = 0, ORANGE = 1, YELLOW = 2, MAGENTA = 3,
	PINK = 4, GREEN = 5, CYAN = 6, PURPLE = 7
};

/**
 * @brief Drawable block object.
 *
 * Stores body and texture of the block.
 * Compile-time constant static variables describe object dimensions.
 */

class Block : public sf::Drawable
{
private:
	sf::RectangleShape body{};
	sf::Texture texture{};

public:
	static constexpr float width = 48.0f;
	static constexpr float height = 24.0f;

	explicit Block(AssetsManager& assets, BlockColor color, float initX, float initY);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::FloatRect getGlobalBounds() const;
};