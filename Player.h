#ifndef PLAYER_H
#define PLAYER_H

#include "all.h"
#include "Moves.h"

class Player {
    private:
        int health;
        int attack;
        int armor = 0;
        int level;
        Moves *moves;
    
    public: 
        Player();  // new player
        Player(int, int, int, int, int, int, int, int);  // load player from file
        int displayMoves();
};


Player::Player() {  // new player
    this->health = 150;
    this->attack = 25;
    this->armor = 15;
    this->level = 1;
    moves = new Moves();
}

Player::Player(int health, int attack, int armor, int level, int s, int w, int b, int p) {  // load player from file
    this->health = health;
    this->attack = attack;
    this->armor = armor;
    this->level = level;
    moves = new Moves(s, w, b, p);
}

int Player::displayMoves() {
    int choice;

    cout << "\n*******************************************************";
    cout << "\n*   1. Slash: " << moves->slashRemaining() <<  "          2. Whirlwind: " << moves->whirlwindRemaining() << "       *";
    cout << "\n*   3. Pierce: " << moves->pierceRemaining() << "         4. Block: " << moves->blockRemaining() << "         *";
    cout << "\n*******************************************************";
    cout << "\n\nPick a move: ";
    cin >> choice;

    while (choice < 1 || choice > 4) {
        cout << "\nChoose again: ";
        cin >> choice;
    }

    return choice;
}

#endif