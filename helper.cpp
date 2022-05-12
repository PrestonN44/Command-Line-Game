#include "headers/helper.h"

vector<string> getSaves(const string path) {
    struct dirent *saveFile;
    DIR *dp;
    vector<string> saves;\
    string t;
    int choice;

    dp = opendir(path.c_str());
    
    while (saveFile = readdir(dp)) {
        string s(saveFile->d_name);
        if (s != "." && s != "..") 
            saves.push_back(s);
    }
    closedir(dp);

    // cut off ".txt" at end of files
    for (int i = 0; i < saves.size(); i++) {
        t = saves.at(i);
        t = t.substr(0, t.length()-4);
        saves.at(i) = t;
    }
    return saves;
}

int listSaveFiles() {
    getSaves("saves/*.txt");   



    return 0;
}

int displayMenu() {
    int choice;

    cout << "\n1. New game";
    cout << "\n2. Load";
    cout << "\n3. Quit\n";
    cout << "\nPick an option: ";
    cin >> choice;

    return choice;
}

bool combat(Player* player, Monster* monster) {
    char continueChoice;
    bool succeed;

    do {
        monster = monsterSpawn();                // spawn monster

        while (monster->isAlive()) {
            succeed = player->attackMonster(monster);
            while (!succeed) {  // verifies the user enters a move with uses remaining
                cout << "\nChoose another move";
                succeed = player->attackMonster(monster);
            }
            if (monster->isAlive()) {
                monster->attackPlayer(player);   // monster attacks
                if (player->isAlive())
                    continue;
                else {
                    return false;                // player died
                }
            }
            else {
                cout << "\n\nMonster killed!\nContinue? (Y/N)\n\n";
                cin >> continueChoice;
                continueChoice = tolower(continueChoice);
                break;
            }
        }
    } while (continueChoice == 'y');

    return true;
}

void saveToFile(Player *player) {
    ofstream outFile;
    string saveFile;
    char saveOrNot;

    cout << "\nWould you like to save your progress? (Y/N)\n";
    cin >> saveOrNot;
    if (tolower(saveOrNot) == 'y') {
        cout << "Enter the name you wish to save as: ";
        cin >> saveFile;
    }
    else return;

    outFile.open("saves/" + saveFile + ".txt");

    outFile << to_string(player->getHealth()) << " " << to_string(player->getAttack()) 
            << " " << to_string(player->getArmor()) << " " << to_string(player->getLevel()) 
            << " " << to_string(player->getSlash()) << " " << to_string(player->getWhirlwind())
            << " " << to_string(player->getBlock()) << " " << to_string(player->getPierce());

    outFile.close();
}

Monster* monsterSpawn() {
    int monsterNum;
    Goblin *goblin;
    Golem *golem;
    Skeleton *skeleton;

    monsterNum = rand() % 3 + 1;

    if (monsterNum == 1) {  // goblin
        goblin = new Goblin();
        return goblin;
    }
    else if (monsterNum == 2) {  // skeleton
        skeleton = new Skeleton();
        return skeleton;
    }
    else {  // golem
        golem = new Golem();
        return golem;
    }
}

Player* loadFile() {
    Player *player;
    ifstream inFile;
    string filename;
    int health, attack, armor, level, s, w, b, p;  
    int choice;
    vector<string> saveFiles;

    saveFiles = getSaves("saves");
    // print options to user
    cout << "\n***** SAVEFILES *****";
    for (int i = 1; i <= saveFiles.size(); i++) {
        cout << endl << i << ". " << saveFiles.at(i-1);
    }
    cout << "\n*********************\n";

    cout << "\nPick 1-" << saveFiles.size() << ": ";
    cin >> choice;

    inFile.open("saves/" + saveFiles.at(choice-1) + ".txt");
    cout << "\"" << saveFiles.at(choice-1) << "\" successfully loaded!\n";
    while (!inFile) {
        cout << "File could not be opened. Enter another number: ";
        cin >> choice;
        inFile.open("saves/" + saveFiles.at(choice-1) + ".txt");
    }

    inFile >> health >> attack >> armor >> level >> s >> w >> b >> p;
    player = new Player(health, attack, armor, level, s, w, b, p);

    inFile.close();

    return player;
}