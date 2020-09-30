//
// Created by kszap on 29.09.2020.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "assets_manager.hpp"

/**
 * @brief Drawable scoreboard, displayed on the bottom of the game window.
 *
 * Contains shapes, fonts, texts which scoreboard consists of,
 * the data is updated from main game class via update() method.
 */

class Scoreboard : public sf::Drawable
{
private:
	sf::RectangleShape body;
	sf::Text score_txt;
	sf::Text highscore_txt;

public:
	explicit Scoreboard(const sf::Font& font, float window_width);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void update(unsigned int score, unsigned int highscore);
};


