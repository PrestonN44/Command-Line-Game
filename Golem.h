#ifndef GOLEM_H
#define GOLEM_H

#include "Monster.h"


class Golem: public Monster {
    private:

    public:
        Golem() : Monster(75, 25) {
            cout << "\nGolem spawned\n";
        }
};

#endif