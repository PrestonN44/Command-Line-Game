#ifndef HELPER_H
#define HELPER_H

#include "all.h"
#include "Player.h"
#include "Monster.h"
#include "Monsters.h"
#include <fstream>
#include <dirent.h>
#include <vector>
#include <time.h>
#include <limits>


vector<string> getSaves(const string);
int displayMenu();
bool combat(Player*, Monster*);
void saveToFile(Player*);
Player* loadFile();
Monster* monsterSpawn();
void deathMessage();

#endif