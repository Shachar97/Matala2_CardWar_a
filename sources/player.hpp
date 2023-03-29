#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

using namespace std;

namespace ariel{
    class Player{
        private:
            string name_;
            int stacksize_, cardesTaken_;
        public:
            Player(string name);
            ~Player();
            Player(Player &player );
            Player operator =(Player &player)=delete;
            Player(Player &&player)=delete;
            Player operator=(Player &&player)=delete;

            int stacksize() const;
            int cardesTaken() const;
            string getName();
            
        };
}
#endif