#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include "item.hpp"
#include "environment_tile.hpp"
#include "worldobject.hpp"
#include "villager.hpp"
#include <utility>
#include <string>

class Navigator
{
    //TODO fields
    public:
        Navigator(std::string currentMap, int xPos, int yPos, char directionFacing);
        Villager* interact(Item* heldItem);
        void walk(char direction); //one of 'n','e','s','w'
        void passDayUpdateMaps();

        //for testing purposes / console version? / maybe art needs it too...
        std::pair<int,int> getPosition();
        char getDirectionFacing();
        WorldObject* getObjectFacing();
        // EnvironmentTile* getEnvTileFacing();

    private:
        std::pair<int,int> position;
        char directionFacing; //one of 'n','e','s','w'
        //TODO more... a map or sth of items, and one of environmenttile
        //and the index or sth of the current map

        void removeWorldObjectAtPosition(std::pair<int,int> position); //operates on current map
        void addWorldObjectAtPosition(std::pair<int,int> position, WorldObject worldObject);
        WorldObject getWorldObjectAtPosition(std::pair<int,int> position);

        struct Map
        {
        };
};

#endif