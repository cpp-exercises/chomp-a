#pragma once

/**
 * A collection of very dumb Chomp players, as an example to the interface of a player.
 * 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include "Player.hpp"

namespace chomp {

	/**
	 * This player always eats the bad cube on the first move, so it always loses.
	 */
	class Loser: public Player {
		public:
			Loser(std::string name=""): Player("Loser["+name+"]") {}
			std::tuple<uint,uint> move(const ChompGame& game) override;
	};

	/**
	 * This player plays an illegal move (out of range), so it always loses.
	 */
	class IllegalMover: public Player {
		public:
			IllegalMover(std::string name=""): Player("IllegalMover["+name+"]") {}
			std::tuple<uint,uint> move(const ChompGame& game) override;
	};

	/**
	 * This player scans the cubes row by row, and eats the first cube it finds.
	 */
	class HorizontalEater: public Player {
		public:
			HorizontalEater(std::string name=""): Player("HorizontalEater["+name+"]") {}
			std::tuple<uint,uint> move(const ChompGame& game) override;
	};

	/**
	 * This player scans the cubes column by column, and eats the first cube it finds.
	 */
	class VerticalEater: public Player {
		public:
			VerticalEater(std::string name=""): Player("VerticalEater["+name+"]") {}
			std::tuple<uint,uint> move(const ChompGame& game) override;
	};
}
