#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
#include <string>

using namespace ariel;
using namespace std;


Card::Card(int number, string type) : number_(number), type_(type){}
    
Card::~Card(){}
// Card::Card(Card &card){
//     number_=card.number_;
//     type_=card.type_;
// }

int Card::getNumber()const { 
    return number_;
}