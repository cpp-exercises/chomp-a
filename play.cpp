/**
 * Implementation of Chomp game.
 * 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include "play.hpp"
#include <string>
#include <tuple>
#include <stdexcept>
#include <iostream>
using namespace std;

namespace chomp {

	// Play a game and return the winner.
	Player& play(uint rows, uint cols, Player& firstPlayer, Player& secondPlayer, bool log) {
		// Create three copies of the board: one official and two for the players, 
		//    so that the players cannot manipulate the official board.
		ChompGame officialGame(rows,cols);
		ChompGame gameForFirstPlayer(rows,cols);
		ChompGame gameForSecondPlayer(rows,cols);

		for (;;) {

			{  // Move of first player:
				auto [row, col] = firstPlayer.move(gameForFirstPlayer);
				if (log) cout << "First player eats (" << row << "," << col << ")" << endl;
				if (row==0 && col==0) {  // losing move - other player wins
					return secondPlayer;
				} else if (!officialGame.legal(row,col)) { // Illegal move - other player wins
					return secondPlayer;
				}
				officialGame.eat(row,col);
				gameForFirstPlayer.eat(row,col);
				gameForSecondPlayer.eat(row,col);
			}

			{  // Move of second player:
				auto [row, col] = secondPlayer.move(gameForSecondPlayer);
				if (log) cout << "Second player eats (" << row << "," << col << ")" << endl;
				if (row==0 && col==0) {  // losing move - other player wins
					return firstPlayer;
				} else if (!officialGame.legal(row,col)) { // Illegal move - other player wins
					return firstPlayer;
				}
				officialGame.eat(row,col);
				gameForFirstPlayer.eat(row,col);
				gameForSecondPlayer.eat(row,col);
			}
		}
		throw logic_error("The game of Chomp did not finish correctly");
	}
}
