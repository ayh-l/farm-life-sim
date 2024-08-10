/**
 * @file navigator.hpp
 * Definition of the Navigator class, which facilitates traversal and interaction within Maps.
 */

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
    public:

        /**
         * Constructs a Navigator, setting fields to defaults.
         */
        Navigator();

        /**
         * Constructs a Navigator, setting fields as specified.
         * 
         * @param currentMap index of current map
         * @param xPos horizontal position of player character on currentMap
         * @param yPos vertical position of player character on currentMap
         * @param directionFacing direction player character is facing (one of 'n', 'e', 's', 'w')
         */
        Navigator(int currentMap, int xPos, int yPos, char directionFacing);

        /**
         * Interacts with the WorldObject and/or EnvironmentTile the player character is facing, according to held item.
         * If the WorldObject is a Villager or an Item to be collected, returns a pointer to it.
         * 
         * @param heldItem pointer to held item (nullptr if none)
         * @return pointer to villager or collectible item being interacted with
         */
        WorldObject* interact(Item* heldItem);

        /**
         * Moves player character one step in given direction as appropriate.
         * May change current map if starting environment tile contains a path.
         * 
         * @param direction cardinal direction to walk, one of 'n', 'e', 's', 'w'
         */
        void walk(char direction); //one of 'n','e','s','w'

        /**
         * Appropriately updates villagers, crops and items for the next in-game day.
         * 
         * If a villager has been spoken to today, their friendship points increase by 5.
         * If a crop is on watered soil, the crop remains alive (and possibly ripens into an item), and otherwise is killed.
         * Any respawning items that have been collected are replaced.
         */
        void passDayUpdateMaps();

        /**
         * Changes current map to map represented by given map id (index).
         * 
         * @param mapId integer in [0,6], id of desired current map
         */
        void changeCurrentMapTo(int mapId);

        /**
         * Sets player character's position as desired.
         * 
         * @param x desired horizontal position of character
         * @param y desired vertical position of character
         */
        void setPosition(int x, int y);

        /**
         * Sets direction player character is facing as desired.
         * 
         * @param direction desired cardinal direction of character, one of 'n', 'e', 's', 'w'
         */
        void setDirectionFacing(char direction);

        /**
         * Returns position of player character on current map.
         * 
         * @return integer pair representing player character's current position, in form <[x position], [y position]>
         */
        std::pair<int,int> getPosition();

        /**
         * Returns position player character is facing
         * 
         * @return integer pair representing position in front of player character, in form <[x position], [y position]>
         */
        std::pair<int,int> getPositionFacing();

        /**
         * Returns direction player character is facing.
         * 
         * @return cardinal direction player character is facing. One of 'n', 'e', 's', 'w'.
         */
        char getDirectionFacing();

        /**
         * Returns pointer to WorldObject player character is facing, if any.
         * 
         * @return pointer to object player character is facing (or nullptr if none)
         */
        WorldObject* getObjectFacing();

        /**
         * Removes WorldObject that player character is facing, if any.
         */
        void removeObjectFacing();

        /**
         * Returns pointer to EnvironmentTile player character is facing, if any.
         * 
         * @return pointer to environment tile player character is facing (or nullptr if none) 
         */
        EnvironmentTile* getEnvTileFacing();

        /**
         * Returns index / map id of current map (see map.hpp for id details!)
         * 
         * @return map id of current map
         */
        int getCurrentMapIndex();

        /**
         * Returns map currently being interacted with
         * 
         * @return current map
         */
        Map getCurrentMap();

        /**
         * Returns vector of all maps
         * 
         * @return vector of maps
         */
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