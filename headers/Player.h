#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Moves.h"
#include "Monster.h"
using namespace std;

class Player {
    private:
        int health;
        int attack;
        int armor;
        int level;
        Moves *moves;
    
    public: 
        Player();  // new player
        Player(int, int, int, int, int, int, int, int);  // load player from file
        int displayMoves();
        bool attackMonster(Monster*);
        void takeDmg(int);
        bool isAlive();

        int getHealth();
        int getAttack();
        int getArmor();
        int getLevel();

        int getSlash();
        int getWhirlwind();
        int getBlock();
        int getPierce();
        
};

#endif