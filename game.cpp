#include "all.h"
#include "Player.h"
#include "Monster.h"
#include <fstream>

void saveToFile();
Player* readFromFile();


int main() {
    Player *player;
    int choice;
    string saveFile;



    cout << "\n1. New game";
    cout << "\n2. Load";
    cout << "\n3. Quit\n";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "\n Name of the file you wish to save game to: ";
            cin >> saveFile;
            player = new Player();
            break;
        case 2:
            player = readFromFile();
            break;
        case 3:
            return 0;
    }

    choice = player->displayMoves();

    delete player;
    return 0;
}

Player* readFromFile() {
    Player *player;
    ifstream inFile;
    string filename;
    int health, attack, armor, level, s, w, b, p;

    cout << "\nFile name to read from: ";
    cin >> filename;
    inFile.open(filename);
    while (!inFile) {
        cout << "File could not be opened. Enter another file name: ";
        cin >> filename;
        inFile.open(filename);
    }

    inFile >> health >> attack >> armor >> level >> s >> w >> b >> p;
    player = new Player(health, attack, armor, level, s, w, b, p);

    inFile.close();

    return player;
}