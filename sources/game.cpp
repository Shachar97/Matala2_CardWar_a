#include "player.hpp"
#include "game.hpp"
#include "card.hpp"

#include <iostream>
#include <string>

using namespace std;

using namespace ariel;

Game::Game(Player p1,Player p2):p1_(p1),p2_(p2){}
Game::~Game(){}
void Game::playTurn(){
    cout << "print playTurn" << endl;
    // p1_.cardesTaken()++;
}
void Game::printLastTurn(){
    cout << "print printLastTurn" << endl;
}
void Game::playAll(){//playes the game untill the end
    cout << "print playAll" << endl;
} 
void Game::printWiner(){// prints the name of the winning player
    cout << "print printWiner" << endl;
} 
void Game::printLog(){// prints all the turns played one line per turn (same format as game.printLastTurn())
    cout << "print printLog" << endl;
} 
void Game::printStats(){// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
    cout << "print printStats" << p1_.getName() << p1_.cardesTaken() <<p1_.stacksize() << p2_.getName() << p2_.cardesTaken() <<p2_.stacksize() << endl;
}
