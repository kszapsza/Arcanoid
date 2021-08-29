//
// Created by kszap on 29.09.2020.
//

#pragma once

#include <memory>
#include <vector>

#include "block.hpp"

/**
 * @brief Utility class managing game levels. Loads level patterns from data file
 * 		  and constructs vector of blocks pointers.
 */

class LevelsManager
{
private:
	AssetsManager& assets;

	const std::unordered_map<char, BlockColor> colorMapping{
			{ 'B', PURPLE }, { 'C', CYAN }, { 'G', GREEN },
			{ 'P', PINK }, { 'M', MAGENTA }, { 'Y', YELLOW },
			{ 'O', ORANGE }, { 'R', RED }
	};

	std::vector<std::string> levelsData;
	std::vector<std::unique_ptr<Block>> blocks;

	bool blockColorMatters{ false };

public:
	friend class Game;

	explicit LevelsManager(AssetsManager& assets);
	void loadLevel(unsigned int levelIndex);

	[[nodiscard]] std::size_t levelsAmount() const;
};


