#pragma once

#include <string>
#include <tuple>
#include "Game.hpp"

namespace chomp {

	class Player {
		private:
			std::string myName;
		public:
			Player(std::string name): myName(name) { }
			std::string name() const { return myName; }
			virtual std::tuple<uint,uint> move(const ChompGame& currentGame) = 0;
	};

	std::ostream& operator<< (std::ostream& out, const Player& player);
}
