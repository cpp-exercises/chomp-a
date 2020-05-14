#pragma once
/**
 * Header file for playing chomp.
 * 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include <string>
#include <vector>

namespace chomp {
	struct ChompGame {
			uint numRows, numCols;

			// remainingCubes[i][j] is true iff the cube at that position was not eaten yet.
			std::vector<std::vector<bool>> remainingCubes;

			ChompGame(uint numRows, uint numCols);

			// Return true iff the move (row,col) is legal, that is, the cube at [row][col] is not eaten yet.
			bool legal(uint row, uint col);

  			// Eat the cube at [row][col] and all the cubes above it and to its right
			void eat(uint row, uint col);
	};
}
