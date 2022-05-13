#include "headers/Monster.h"

Monster::Monster(int health, int attack) {
    this->health = health;
    this->attack = attack;
}

void Monster::takeDmg(int dmg) {
    cout << "\nYou dealt " << to_string(dmg) << " damage!\n";
    health -= dmg;
    if (health > 0)
        cout << "Monster has " << to_string(health) << " health remaining\n";
}

bool Monster::isAlive() { 
    return health > 0; 
}

// VIRTUAL FUNCTIONS
void Monster::attackPlayer(Player*) {} 
void Monster::art() {}







