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
        Navigator();
        Navigator(int currentMap, int xPos, int yPos, char directionFacing);
        WorldObject* interact(Item* heldItem); //if facing an item (pickupable) or villager, returns pointer to it.
        void walk(char direction); //one of 'n','e','s','w'
        void passDayUpdateMaps();
        void changeCurrentMapTo(int mapId); //sets position to default
        void setPosition(int x, int y);
        void setDirectionFacing(char direction);

        //for testing purposes / console version? / maybe art needs it too...
        std::pair<int,int> getPosition();
        std::pair<int,int> getPositionFacing();
        char getDirectionFacing();
        WorldObject* getObjectFacing();
        void removeObjectFacing();
        EnvironmentTile* getEnvTileFacing();
        int getCurrentMapIndex();
        Map getCurrentMap();

    private:
        std::pair<int,int> position;
        char directionFacing; //one of 'n','e','s','w'
        int currentMap;
        std::vector<Map> maps;
};

#endif