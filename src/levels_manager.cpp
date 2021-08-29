//
// Created by kszap on 29.09.2020.
//

#include <fstream>

#include "block.hpp"
#include "levels_manager.hpp"

LevelsManager::LevelsManager(AssetsManager& assets)
		: assets(assets)
{
	std::ifstream levelsInput;
	levelsInput.open("..\\assets\\levels.dat", std::ios::in);

	if (!levelsInput.is_open())
	{
		std::cerr << R"(Cannot read "..\\assets\\levels.dat" data. Is level data file missing?)"
				  << std::endl;

		exit(EXIT_FAILURE);
	}
	else
	{
		std::string level;
		std::string lineBuffer;

		while (!levelsInput.eof())
		{
			std::getline(levelsInput, lineBuffer);

			if (lineBuffer.at(0) != '#')
			{
				level += lineBuffer;
			}
			else
			{
				if (!level.empty())
				{
					levelsData.emplace_back(level);
					level.clear();
				}
			}
		}

		levelsInput.close();
	}
}

void LevelsManager::loadLevel(const unsigned int levelIndex)
{
	blockColorMatters = (levelIndex == 0);

	blocks.clear();
	blocks.reserve(80);

	float posX{ Block::width / 2 }, posY{ 2 * Block::height };

	for (std::size_t countForNewline{};
		 const char ch : levelsData.at(levelIndex))
	{
		if (ch != '.')
		{
			blocks.emplace_back(std::make_unique<Block>(assets,
					colorMapping.at(ch), posX, posY));
		}

		++countForNewline;

		if (countForNewline == 10)
		{
			posX = Block::width / 2;
			posY += Block::height;
			countForNewline = 0;
		}
		else
		{
			posX += Block::width;
		}
	}
}

std::size_t LevelsManager::levelsAmount() const
{
	return levelsData.size();
}
