//
// Created by kszap on 29.09.2020.
//

#include "scoreboard.hpp"

Scoreboard::Scoreboard(const sf::Font& font, const float window_width)
{
	body.setSize({ window_width, 80.0f });
	body.setPosition({ 0.0f, 700.0f });
	body.setFillColor(sf::Color::Black);
	body.setOutlineColor(sf::Color::White);

	score_txt.setCharacterSize(20);
	score_txt.setPosition(body.getPosition().x + 10.0f,
			body.getPosition().y + 12.0f);
	score_txt.setFont(font);
	score_txt.setFillColor(sf::Color::White);

	highscore_txt.setCharacterSize(20);
	highscore_txt.setPosition(body.getPosition().x + body.getSize().x / 2 + 10.0f,
			body.getPosition().y + 12.0f);
	highscore_txt.setFont(font);
	highscore_txt.setFillColor(sf::Color::White);
}

void Scoreboard::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(body, states);
	target.draw(score_txt, states);
	target.draw(highscore_txt, states);
}

void Scoreboard::update(const unsigned int score, const unsigned int highscore)
{
	score_txt.setString("SCORE\n" + std::to_string(score));
	highscore_txt.setString("HIGH SCORE\n" + std::to_string(highscore));
}