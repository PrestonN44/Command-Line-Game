#include "headers/helper.h"


// DISPLAY THE MAIN MENU
int displayMenu() {
    int choice;

    cout << "\n1. New game";
    cout << "\n2. Load";
    cout << "\n3. Quit\n";
    choice = validateInt(3);

    return choice;
}

// COMBAT PHASE
bool combat(Player* player, Monster* monster) {
    char continueChoice;
    bool succeed;

    do {
        monster = monsterSpawn();                // spawn monster
        while (monster->isAlive()) {
            monster->art();
            succeed = player->attackMonster(monster);
            while (!succeed) {  // verifies the user enters a move with uses remaining
                cout << "\nChoose another move";
                succeed = player->attackMonster(monster);
            }
            if (monster->isAlive()) {
                monster->attackPlayer(player);   // monster attacks
                if (player->isAlive())
                    continue;
                else return false;                // player died
            }
            else {
                player->updateMonstersKilled();
                cout << "\nMonster killed!\nKills: " << player->getMonstersKilled() << "\nDo you wish to continue?";
                continueChoice = validateChar();
                break;
            }
        }
    } while (continueChoice == 'y');
    return true;
}

// SAVE PLAYERS PROGRESS TO A FILE
void saveToFile(Player *player) {
    ofstream outFile;
    string saveFile;
    char saveOrNot;

    cout << "\nWould you like to save your progress?";
    saveOrNot = validateChar();
    if (saveOrNot == 'y') {
        cout << "Enter the name you wish to save as: ";
        cin >> saveFile; 
    }
    else return;

    outFile.open("saves/" + saveFile + ".txt");

    outFile << to_string(player->getHealth()) << " " << to_string(player->getAttack()) 
            << " " << to_string(player->getArmor()) << " " << to_string(player->getLevel()) 
            << " " << to_string(player->getSlash()) << " " << to_string(player->getWhirlwind())
            << " " << to_string(player->getBlock()) << " " << to_string(player->getPierce())
            << " " << to_string(player->getMonstersKilled());

    outFile.close();
}

// SPAWN NEW MONSTER
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

// GET ALL SAVE FILES
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

// LOAD PLAYER STATS FROM A FILE
Player* loadFile() {
    Player *player;
    ifstream inFile;
    string filename;
    int health, attack, armor, level, s, w, b, p, mk;  
    int choice;
    vector<string> saveFiles;

    saveFiles = getSaves("saves");
    if (saveFiles.size() < 1) {
        cout << "\nThere are no current save files to load from. Creating new character.\n";
        player = new Player();
        return player;
    }
    // print options to user
    cout << "\n***** SAVEFILES *****";
    for (int i = 1; i <= saveFiles.size(); i++) {
        cout << endl << i << ". " << saveFiles.at(i-1);
    }
    cout << "\n*********************\n\n";


    cout << "Enter 1-" << saveFiles.size() << " to load a file.\n";
    cout << "Enter 0 to return to main menu.\n";
    cin >> choice;
    while (cin.fail() || (choice < 0 || choice > saveFiles.size())) {
        cout << "Invalid input. Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;
    }
    if (choice == 0) 
        return NULL;

    filename = "saves/" + saveFiles.at(choice-1) + ".txt";
    inFile.open(filename);
    cout << "\n\"" << saveFiles.at(choice-1) << "\" successfully loaded!\n";

    while (!inFile) {
        cout << "File could not be opened. Choose another.";
        choice = validateInt(saveFiles.size());
        filename = "saves/" + saveFiles.at(choice-1) + ".txt";
        inFile.open(filename);
    }

    inFile >> health >> attack >> armor >> level >> s >> w >> b >> p >> mk;
    player = new Player(health, attack, armor, level, s, w, b, p, mk);

    inFile.close();
    remove(filename.c_str());  // remove the file from the save files list

    return player;
}

void deathMessage() {
    cout << endl << endl;
    cout << "   %%      %     #######%     #%       #*         #%###(%#     ,%.    #######,   #%###(%#\n";     
    cout << "    ##   */    #%        #%   ##       #*         %%       %#  ,#.   .%          %%       %#\n";   
    cout << "      %##      %%        (%   ##       #*         %%       #%  ,#.   .%%##%      %%       #%\n";  
    cout << "      ,%       #%        %%   #%       #,         %%       %#  ,#.   .%          %%       %#\n";   
    cout << "      ,%        (%(#######     %(#####.(          %(######(    ,(     %#####.%   %(######(\n";                                                                                                                                                 
}