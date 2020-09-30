//
// Created by kszap on 30.09.2020.
//

#include "game.hpp"

/**
 * @brief Message font must be already loaded when constructing this object in order to make
 * 		  text aligned center properly! Otherwise, use setString() or alignCenter().
 * @param target Render target to draw to.
 */
MessageBox::MessageBox(const sf::Font& font, const std::string& message, MessageSeverity severity)
		:message(message), severity(severity)
{
	text.setFont(font);
	text.setCharacterSize(20u);

	text.setFillColor(color_mapping.at(severity));
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(2.0f);
	text.setStyle(sf::Text::Regular);

	text.setString(message);
	alignCenter();
}

/**
 * @brief Because text font is loaded only in game's setup() method (not in constructor)
 * 		  changing text origin to its center from msgbox constructor level does not work.
 * 		  String has to be passed from setup() after loading the font.
 * @param target Render target to draw to.
 */
void MessageBox::setString(const std::string& string)
{
	message = string;
	text.setString(message);
	alignCenter();
}

/**
 * @brief sf::Drawable's draw() method override. Draws the object to a render target.
 * @param target Render target to draw to.
 * @param states Current render states.
 */
void MessageBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(text, states);
}

void MessageBox::alignCenter()
{
	const auto x_position = (float(Game::window_width) - text.getGlobalBounds().width) / 2.0f;
	const auto y_position = (float(Game::window_height) - text.getGlobalBounds().height) / 2.0f + 128.0f;

	text.setPosition(x_position, y_position);
}