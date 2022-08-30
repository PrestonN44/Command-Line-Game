#include "headers/helper.h"

/*
TODO: leveling system
TODO: more monster moves
TODO: tavern for healing and refilling moves
TODO: more weapons/monsters
*/

int main() {
    Player *player;
    Monster *monster;
    int intChoice, num, choice;
    char charChoice;
    char quit = 'n';
    srand(time(0)); 

    do {
        choice = displayMenu();
        switch (choice) {
            case 1: player = new Player();
                    if (combat(player, monster))  // player willingly exits combat
                        saveToFile(player);
                    else deathMessage();          // player dies
                    break;
            case 2: player = loadFile();
                    if (player == NULL) 
                        break;
                    if (combat(player, monster))  
                        saveToFile(player);
                    else deathMessage();          
                    break;
            case 3: quit = 'y';
        }
    } while (quit != 'y');

    delete monster;
    delete player;
    return 0;
}
