#pragma once
/**
 * Header file for playing chomp.
 * 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include "Player.hpp"

namespace chomp {
	// Play a game of Chomp on a board of the given size, and return a reference to the winner.
	// If "log" is true, it also prints each move to cout.
	Player& play(uint numRows, uint numCols, Player& firstPlayer, Player& secondPlayer, bool log=false);
}
