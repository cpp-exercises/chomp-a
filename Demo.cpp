/**
  Demo for the Chomp game.

  @author Erel Segal-Halevi
  @since  2020-05
**/

#include <iostream>
#include <complex>
#include "play.hpp"
#include "DemoPlayers.hpp"

using namespace std;

int main() {
    chomp::HorizontalEater horizontal1("1"), horizontal2("2");
    chomp::Player& winner = chomp::play(7, 4, horizontal1, horizontal2);
    cout << winner << endl;  // HorizontalEater[1]

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

    return 0;
}
