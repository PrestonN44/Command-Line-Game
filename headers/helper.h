#ifndef HELPER_H
#define HELPER_H

#include <fstream>
#include <dirent.h>
#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "Monsters.h"
#include <vector>
#include <time.h>
using namespace std;
    
vector<string> getSaves(const string);
int listSaveFiles();
int displayMenu();
bool combat(Player*, Monster*);
void saveToFile(Player*);
Player* loadFile();
Monster* monsterSpawn();

#endif