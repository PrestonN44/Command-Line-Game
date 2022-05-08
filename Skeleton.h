#ifndef SKELETON_H
#define SKELETON_H

#include "Monster.h"


class Skeleton: public Monster {
    private:

    public:
        Skeleton() : Monster(25, 75) {
            cout << "\nSkeleton spawned\n";
        }

};

#endif