#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
#include <string>
using namespace ariel;
using namespace std;

// Player::Player(){
//     name_="alice";
//     stacksize_=0;
//     cardesTaken_=0;
// }
Player::Player(string name): name_(name),stacksize_(26),cardesTaken_(0){}
Player::~Player(){}
Player::Player(Player &player): name_(player.name_),stacksize_(26),cardesTaken_(0){}
int Player::stacksize() const{
    return stacksize_;
}
int Player::cardesTaken() const{
    return cardesTaken_;
}
string Player::getName(){
    return name_;
}