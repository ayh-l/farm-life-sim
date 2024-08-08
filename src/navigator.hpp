#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include "item.hpp"
#include "environment_tile.hpp"
#include "worldobject.hpp"
#include "villager.hpp"
#include "map.hpp"
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

        /**
         * Appropriately updates villagers, crops and items for the next in-game day.
         * 
         * If a villager has been spoken to today, their friendship points increase by 5.
         * If a crop is on watered soil, the crop remains alive (and possibly ripens into an item), and otherwise is killed.
         * Any respawning items that have been collected are replaced.
         */
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
        std::vector<Map> getMaps();

    private:
        std::pair<int,int> position;
        char directionFacing; //one of 'n','e','s','w'
        int currentMap;
        std::vector<Map> maps;
        std::vector<Villager*> villagers;
        std::vector<std::pair<Crop*, std::pair<int,int> > > crops;
};

#endif