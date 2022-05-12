#include "headers/Player.h"


// NEW CHARACTER CREATED
Player::Player() {  
    this->health = 250;
    this->attack = 25;
    this->armor = 5;
    this->level = 1;
    moves = new Moves();
}

// CHARACTER LOADED FROM FILE
Player::Player(int health, int attack, int armor, int level, int s, int w, int b, int p) {  
    this->health = health;
    this->attack = attack;
    this->armor = armor;
    this->level = level;
    moves = new Moves(s, w, b, p);
}

// PLAYER ATTACKS MONSTER
bool Player::attackMonster(Monster* monster) {
    int dmg = 0, choice;

    choice = displayMoves();                // player attack
        
    switch (choice) {
        case 1: if (moves->updateSlash())
                    dmg = rand() % 10 + 5;  // slash
                else return false;
                break;
        case 2: if (moves->updateWhirlwind())
                    dmg = rand() % 50 + 15; // whirlwind
                else return false;
                break;
        case 3: if (moves->updatePierce())
                    dmg = rand() % 20 + 10;  // pierce
                else return false;
                break;
        case 4: if (moves->updateBlock())
                    armor += 5;             // block
                else return false;
    }

    monster->takeDmg(dmg);
    return true;
}

// DISPLAY MOVES AND LET USER PICK ONE
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

// PLAYER TAKES DAMAGE FROM MONSTER
void Player::takeDmg(int dmg) {
    dmg -= armor;

    if (dmg > 0) { 
        cout << "You take " << to_string(dmg) << " damage!\n\n";
        health -= dmg;
        if (health > 0)
            cout << "You have " << to_string(health) << " health remaining\n";
    }
    else 
        cout << "\nYou take no damage\n";   
}

// CHECK IF PLAYER IS ALIVE
bool Player::isAlive() { return health > 0; }

/// GET PLAYER STATS ///
int Player::getHealth() { return health; }
int Player::getAttack() { return attack; }
int Player::getArmor() { return armor; }
int Player::getLevel() { return level; }

/// GET MOVES REMAINING USES ///
int Player::getSlash() { return moves->getSlash(); }
int Player::getWhirlwind() { return moves->getWhirlwind(); }
int Player::getBlock() { return moves->getBlock(); }
int Player::getPierce() { return moves->getPierce(); }
        



