#ifndef ENVIRONMENT_TILE_H
#define ENVIRONMENT_TILE_H

#include <string>

class EnvironmentTile
{
    public:
    //TODO image
        EnvironmentTile(std::string name, int tilled, int watered, bool walkable, bool fishable);
        void till();
        void water();
        bool isWalkable();
        bool isFishable();
        bool isWatered();
        bool isTilled();
        std::string getName();

    private:
        int watered; // 0-no, 1-yes, 2-not waterable
        int tilled; // 0-no, 1-yes, 2-not waterable
        bool walkable;
        bool fishable;
        std::string name;
};

#endif