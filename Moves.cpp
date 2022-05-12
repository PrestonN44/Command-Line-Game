#include "headers/Moves.h"

// NEW CHARACTER CREATED
Moves::Moves() {  
    this->slash.remainingUses = 25;
    this->whirlwind.remainingUses = 5;
    this->block.remainingUses = 10;
    this->pierce.remainingUses = 15;
}

// CHARACTER LOADED FROM FILE
Moves::Moves(int s, int w, int b, int p) {  
    this->slash.remainingUses = s;
    this->whirlwind.remainingUses = w;
    this->block.remainingUses = b;
    this->pierce.remainingUses = p;
}

/// GET REMAINING/MAX USES FOR A MOVE ///
string Moves::slashRemaining() { return to_string(slash.remainingUses) + "/" + to_string(slash.maxUses); }
string Moves::whirlwindRemaining() { return to_string(whirlwind.remainingUses) + "/" + to_string(whirlwind.maxUses); }
string Moves::blockRemaining() { return to_string(block.remainingUses) + "/" + to_string(block.maxUses); }
string Moves::pierceRemaining() { return to_string(pierce.remainingUses) + "/" + to_string(pierce.maxUses); }

/// GET REMAINING USES OF A MOVE ///
int Moves::getSlash() { return slash.remainingUses; }
int Moves::getWhirlwind() { return whirlwind.remainingUses; }
int Moves::getBlock() { return block.remainingUses; }
int Moves::getPierce() { return pierce.remainingUses; }

/// UPDATE REMAINING USES OF A MOVE ///
bool Moves::updateSlash() { 
    if (slash.remainingUses > 0) {
        slash.remainingUses--; 
        return true;
    }
    else 
        return false;
}

bool Moves::updateWhirlwind() { 
    if (whirlwind.remainingUses > 0) {
        whirlwind.remainingUses--; 
        return true;
    }
    else 
        return false;
}

bool Moves::updatePierce() { 
    if (pierce.remainingUses > 0) {
        pierce.remainingUses--; 
        return true;
    }
    else 
        return false;
}

bool Moves::updateBlock() { 
    if (block.remainingUses > 0) {
        block.remainingUses--; 
        return true;
    }
    else 
        return false;
}


