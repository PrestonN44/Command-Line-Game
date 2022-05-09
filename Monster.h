#ifndef MONSTER_H
#define MONSTER_H

#include "all.h"


class Monster {
    protected:
        int health;
        int attack;

    public:
        Monster(int health, int attack) {
            this->health = health;
            this->attack = attack;
        }

        int getHealth() { return health; }
        int getAttack() { return attack; }
        
};

#endif