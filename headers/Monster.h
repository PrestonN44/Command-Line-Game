#ifndef MONSTER_H
#define MONSTER_H

class Player;  // for access to Player
#include <iostream>
using namespace std;

class Monster {
    protected:
        int health;
        int attack;
        string name;

    public:
        Monster(int, int);
        void takeDmg(int dmg);
        bool isAlive();
        virtual void attackPlayer(Player*);
};

#endif