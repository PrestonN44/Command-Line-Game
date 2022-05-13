#ifndef PLAYER_H
#define PLAYER_H

#include "all.h"
#include "Moves.h"
#include "Monster.h"


class Player {
    private:
        int health;
        int attack;
        int armor;
        int level;
        int monstersKilled;
        Moves *moves;
    
    public: 
        Player();  // new player
        Player(int, int, int, int, int, int, int, int, int);  // load player from file
        int displayMoves();
        bool attackMonster(Monster*);
        void takeDmg(int);
        bool isAlive();
        void updateMonstersKilled();
        
        int getHealth();
        int getAttack();
        int getArmor();
        int getLevel();
        int getMonstersKilled();

        int getSlash();
        int getWhirlwind();
        int getBlock();
        int getPierce();


        
};

#endif