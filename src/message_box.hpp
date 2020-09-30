//
// Created by kszap on 30.09.2020.
//

#pragma once

#include <cstddef>
#include <string>
#include <unordered_map>

#include <SFML/Graphics/Text.hpp>

enum class MessageSeverity : std::uint8_t
{
	constructive, info, warning, error
};

class MessageBox : public sf::Drawable
{
private:
	sf::Text text;

	std::string message;
	MessageSeverity severity;

	const std::unordered_map<MessageSeverity, sf::Color> color_mapping{
			{ MessageSeverity::constructive, sf::Color::Green },
			{ MessageSeverity::info, sf::Color::White },
			{ MessageSeverity::warning, sf::Color::Yellow },
			{ MessageSeverity::error, sf::Color::Red }
	};

public:
	explicit MessageBox(const sf::Font& font, const std::string& message = "",
			MessageSeverity severity = MessageSeverity::info);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setString(const std::string& message);
	void alignCenter();
};


