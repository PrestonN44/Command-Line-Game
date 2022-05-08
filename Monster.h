#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
using namespace std;


class Monster {
    protected:
        int health;
        int attack;

    public:
        Monster(int health, int attack) {
            this->health = health;
            this->attack = attack;
        }
        
};

#endif