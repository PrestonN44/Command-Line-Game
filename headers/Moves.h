#ifndef MOVES_H
#define MOVES_H

#include <iostream>
using namespace std;

// MOVES PLAYER HAS ACCESS TO
struct Slash {
    int remainingUses;
    int maxUses = 25;
};
struct Whirlwind {
    int remainingUses;
    int maxUses = 5;
};
struct Block {
    int remainingUses;
    int maxUses = 10;
};
struct Pierce {
    int remainingUses;
    int maxUses = 15;
};

class Moves {
    private:
        Slash slash;
        Whirlwind whirlwind;
        Block block;
        Pierce pierce;

    public:
        Moves(); 
        Moves(int, int, int, int); 

        string slashRemaining();
        string whirlwindRemaining();
        string blockRemaining();
        string pierceRemaining();

        int getSlash();
        int getWhirlwind();
        int getBlock();
        int getPierce();

        bool updateSlash();
        bool updateWhirlwind();
        bool updatePierce();
        bool updateBlock();
};

#endif