#include "doctest.h"

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

#include <string>

using namespace ariel;
using namespace std;

//this case check that the parameters of the game had set before the game begin
TEST_CASE("set the game"){
    //SET
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    //start the game with 26 card for each
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);

    //no turns so no cards winner:
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

//this case check that the parameters change asthey should everery turn that played
TEST_CASE("check playturn func") {
    //SET
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    //play all turns:
    for (int i = 1; i <= 26; i++)
    {
        if (p1.cardesTaken()+p2.cardesTaken()==52)
        {
            //there is a winner!
            break;
        }
        
        game.playTurn();
        CHECK(p1.stacksize()<=(26-i));//equal if no draw was played, else is less then
        CHECK(p2.stacksize()<=(26-i));//equal if no draw was played, else is less then

        CHECK(p1.stacksize()==p2.stacksize());//every turn the player have the same num of cards in the stack

        CHECK(p1.cardesTaken()+p2.cardesTaken()>=(2*i));////equal if no draw has played, otherwise its more

        CHECK(p1.stacksize()+p2.stacksize()+p1.cardesTaken()+p2.cardesTaken()==52);    
    }
    //end game:
    CHECK(p1.stacksize()==0);
    CHECK(p2.stacksize()==0);
    CHECK(p1.cardesTaken()+p2.cardesTaken()==52);

}

//this case check that the parameters change as they should after playall func played
TEST_CASE("check play all func:"){
    //SET
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    game.playAll();

    CHECK(p1.stacksize()==0);
    CHECK(p2.stacksize()==0);
    CHECK(p1.cardesTaken()+p2.cardesTaken()==52);
}

//this case check that the throw exeptions of the differents function
TEST_CASE("check exceptions"){
    //SET
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    CHECK_THROWS(game.printWiner());//no winner yet
    CHECK_THROWS(game.printLastTurn());// game didnt start yet

    CHECK_NOTHROW(game.printLog());//empty
    CHECK_NOTHROW(game.printStats());//empty
    
    game.playAll();
    
    CHECK_NOTHROW(game.printWiner());//have a winner

    CHECK_THROWS(game.playTurn());//game had ended
    CHECK_THROWS(game.playAll());//game had ended

}