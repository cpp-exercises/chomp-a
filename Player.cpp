#include "Player.hpp"

namespace chomp {
	std::ostream& operator<< (std::ostream& out, const Player& player)  {
		out << player.name();
		return out;
	}
}
