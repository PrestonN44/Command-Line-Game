#ifndef MOVES_H
#define MOVES_H

#include "all.h"


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
        Moves(); // new character
        Moves(int, int, int, int); // load character from file

        string slashRemaining() {
            return to_string(slash.remainingUses) + "/" + to_string(slash.maxUses);
        }
        string whirlwindRemaining() {
            return to_string(whirlwind.remainingUses) + "/" + to_string(whirlwind.maxUses);
        }
        string blockRemaining() {
            return to_string(block.remainingUses) + "/" + to_string(block.maxUses);
        }
        string pierceRemaining() {
            return to_string(pierce.remainingUses) + "/" + to_string(pierce.maxUses);
        }
};

Moves::Moves() {  // new character
    this->slash.remainingUses = 25;
    this->whirlwind.remainingUses = 5;
    this->block.remainingUses = 10;
    this->pierce.remainingUses = 15;
}

Moves::Moves(int s, int w, int b, int p) {  // load character from file
    this->slash.remainingUses = s;
    this->whirlwind.remainingUses = w;
    this->block.remainingUses = b;
    this->pierce.remainingUses = p;
}

#endif