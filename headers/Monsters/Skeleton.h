#ifndef SKELETON_H
#define SKELETON_H

#include "../Monster.h"


class Skeleton: public Monster {
    private:

    public:
        Skeleton() : Monster(25, 75) {
            cout << "\nSkeleton spawned\n";
            name = "Skeleton";
        }
        void attackPlayer(Player *player) {
            int dmg = 0;

            dmg = rand() % attack + 1;
            cout << "\nSkeleton used Bone Crush\n";

            player->takeDmg(dmg);
        }

};

#endif