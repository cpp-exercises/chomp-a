/**
 * Implementation of bull-pgia game
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */

#include "Game.hpp"

using namespace std;

namespace chomp {
	ChompGame::ChompGame(uint numRows, uint numCols): 
		numRows(numRows), numCols(numCols), 
		remainingCubes(numRows, vector<bool>(numCols,true)) {	}

	bool ChompGame::legal(uint row, uint col) {
		return 
			row<numRows && 
			col<numCols &&
			remainingCubes[row][col];
	}

	void ChompGame::eat(uint row, uint col) {
		for (uint i=row; i<numRows; ++i) {
			for (uint j=col; j<numCols; ++j) {
				remainingCubes[i][j] = false;
			}
		}
	}
}

