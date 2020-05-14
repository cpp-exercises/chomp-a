/**
 * A collection of very dumb Chomp players, as an example to the interface of a player.
 * 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include "DemoPlayers.hpp"

namespace chomp {
	/**
	 * This player always eats the bad cube on the first move, so it always loses.
	 */
	std::tuple<uint,uint> Loser::move(const ChompGame& game) {
		return {0, 0};
	}

	/**
	 * This player plays an illegal move (out of range), so it always loses.
	 */
	std::tuple<uint,uint> IllegalMover::move(const ChompGame& game) {
		return {game.numRows, 0};
	}

	/**
	 * This player scans the cubes row by row, and eats the first cube it finds.
	 */
	std::tuple<uint,uint> HorizontalEater::move(const ChompGame& game) {
		for (uint row=game.numRows; row>0; --row) {
			for (uint col=game.numCols; col>0; --col) {
				if (game.remainingCubes[row-1][col-1]) {
					return {row-1,col-1};
				}
			}
		}
		return {0,0};  // if no move is found - surrender
	}


	/**
	 * This player scans the cubes column by column, and eats the first cube it finds.
	 */
	std::tuple<uint,uint> VerticalEater::move(const ChompGame& game) {
		for (uint col=game.numCols; col>0; --col) {
			for (uint row=game.numRows; row>0; --row) {
				if (game.remainingCubes[row-1][col-1]) {
					return {row-1,col-1};
				}
			}
		}
		return {0,0};  // if no move is found - surrender
	}
	
}
