#include "headers/helper.h"


int main() {
    Player *player;
    Monster *monster;
    int choice;
    char quit;

    srand(time(0)); 
   
    do {
        choice = displayMenu();

        switch (choice) {
            case 1: player = new Player();
                    if (combat(player, monster))  // player willingly exits combat
                        saveToFile(player);
                    else  // player died
                        cout << "\nYou died!";
                    break;
            case 2: player = loadFile();
                    if (combat(player, monster))  // player willingly exits combat
                        saveToFile(player);
                    else  // player died
                        cout << "\nYou died!";
                    break;
            case 3: quit = 'n';
        }

    } while (quit != 'n');

    delete monster;
    delete player;

    return 0;
}
