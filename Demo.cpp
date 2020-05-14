/**
  Demo for the Chomp game.

  @author Erel Segal-Halevi
  @since  2020-05
**/

#include <iostream>
#include <complex>
#include <cstdlib>
#include "play.hpp"     // You have to write this file
#include "Winner.hpp"   // You have to write this file
#include "DemoPlayers.hpp"

using namespace std;

int main() {
    chomp::HorizontalEater horizontal1("1"), horizontal2("2");
    chomp::Player& the_winner = chomp::play(7, 4, horizontal1, horizontal2);
    cout << the_winner << endl;  // HorizontalEater[1]

    chomp::Loser loser;
    cout << chomp::play(7, 4, horizontal1, loser) << endl;  // HorizontalEater[1]
    cout << chomp::play(7, 4, loser, horizontal2) << endl;  // HorizontalEater[2]
    cout << chomp::play(7, 5, horizontal1, horizontal2) << endl;  // HorizontalEater[2]

    chomp::IllegalMover illegal;
    cout << chomp::play(7, 5, illegal, loser) << endl;  // Loser[]
    cout << chomp::play(7, 5, loser, illegal) << endl;  // IllegalMover[]

    chomp::VerticalEater vertical1("1");
    cout << chomp::play(7, 4, horizontal1, vertical1) << endl;  // HorizontalEater[1]
    cout << chomp::play(7, 4, vertical1, horizontal1) << endl;  // VerticalEater[1]

    chomp::Winner winner("Winner");  // This is a class you have to write!
    for (uint i=0; i<100; ++i) {
        uint rows = rand() % 20 + 5;
        uint cols = rand() % 20 + 5;
        cout << chomp::play(rows, cols, winner, horizontal1) << endl;  // Winner
        cout << chomp::play(rows, cols, horizontal1, winner) << endl;  // Winner
        cout << chomp::play(rows, cols, winner, vertical1) << endl;  // Winner
        cout << chomp::play(rows, cols, vertical1, winner) << endl;  // Winner
    }

    return 0;
}
