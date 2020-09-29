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

	const std::unordered_map<char, BlockColor> color_mapping{
			{ 'B', purple }, { 'C', cyan }, { 'G', green },
			{ 'P', pink }, { 'M', magenta }, { 'Y', yellow },
			{ 'O', orange }, { 'R', red }
	};

	std::vector<std::string> levels_data;
	std::vector<std::unique_ptr<Block>> blocks;

	bool block_color_matters{ false };

public:
	friend class Game;

	explicit LevelsManager(AssetsManager& assets);
	void loadLevel(unsigned int level_index);

	[[nodiscard]] std::size_t levelsAmount() const;
};


