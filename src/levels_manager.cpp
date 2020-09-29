//
// Created by kszap on 29.09.2020.
//

#include <fstream>

#include "block.hpp"
#include "levels_manager.hpp"

LevelsManager::LevelsManager(AssetsManager& assets)
		:assets(assets)
{
	std::ifstream levels_input;
	levels_input.open("..\\assets\\levels.dat", std::ios::in);

	if (!levels_input.is_open())
	{
		std::cerr << R"(Cannot read "..\\assets\\levels.dat" data. Is level data file missing?)"
				  << std::endl;

		exit(EXIT_FAILURE);
	}
	else
	{
		std::string level;
		std::string line_buffer;

		while (!levels_input.eof())
		{
			std::getline(levels_input, line_buffer);

			if (line_buffer.at(0) != '#')
			{
				level += line_buffer;
			}
			else
			{
				levels_data.emplace_back(level);
				level.clear();
			}
		}

		levels_input.close();
	}
}

void LevelsManager::loadLevel(const unsigned int level_index)
{
	block_color_matters = (level_index == 0);

	blocks.clear();
	blocks.reserve(80);

	float pos_x{ Block::width / 2 }, pos_y{ 2 * Block::height };

	for (std::size_t count_for_newline{};
		 const char ch : levels_data.at(level_index))
	{
		if (ch != '.')
		{
			blocks.emplace_back(std::make_unique<Block>(assets,
					color_mapping.at(ch), pos_x, pos_y));
		}

		++count_for_newline;

		if (count_for_newline == 10)
		{
			pos_x = Block::width / 2;
			pos_y += Block::height;
			count_for_newline = 0;
		}
		else
		{
			pos_x += Block::width;
		}
	}
}

std::size_t LevelsManager::levelsAmount() const
{
	return levels_data.size();
}
