#ifndef MONSTER_H
#define MONSTER_H

class Player;  // for access to Player
#include "all.h"

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
        virtual void art();
};

#endif