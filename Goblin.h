#ifndef GOBLIN_H
#define GOBLIN_H

#include "Monster.h"


class Goblin: public Monster {
    private:

    public:
        Goblin() : Monster(50, 50) {
            cout << "\nGoblin spawned\n";
        }
};

#endif