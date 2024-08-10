/**
 * @file map.cpp
 * Definition of the Map class, a map containing positions of objects and environment tiles.
 */

#ifndef MAP_H
#define MAP_H

#include "worldobject.hpp"
#include "environment_tile.hpp"
#include "navigator.hpp"
#include <utility>
#include <string>
#include <unordered_map>

class Map
{
    public:

        /**
         * Constructs a map according to given id.
         * 
         * @param mapId denotes which map should be constructed: 0 = farm, 1 = town, 2 = forest, 3 = home, 4 = house1, 5 = house2, 6 = stumphouse.
         */
        Map(int mapId);

        /**
         * Removes WorldObject at given position (if any).
         * 
         * @param x horizontal position of object to be removed
         * @param y vertical position of object to be removed
         */
        void removeWorldObjectAtPosition(int x, int y);

        /**
         * Adds a WorldObject at given position, replacing any existing WorldObject at that position.
         * 
         * @param x desired horizontal position of object
         * @param y desired vertical position of object
         * @param worldObject object to be added to map
         */
        void addWorldObjectAtPosition(int x, int y, WorldObject worldObject);

        /**
         * Returns a pointer to WorldObject at given position (nullptr if no object at that position).
         * 
         * @param x horizontal position of object
         * @param y vertical position of object
         * @return pointer to WorldObject at given position
         */
        WorldObject* getWorldObjectAtPosition(int x, int y);

        /**
         * Adds an EnvironmentTile at given position, replacing any existing tile at that position.
         * 
         * @param x desired horizontal position of tile
         * @param y desired vertical position of tile
         * @param environmentTile tile to be added to map
         */
        void addEnvironmentTileAtPosition(int x, int y, EnvironmentTile environmentTile);

        /**
         * Returns a pointer to EnvironmentTile at given position (nullptr if no object at that position).
         * 
         * @param x horizontal position of tile
         * @param y vertical position of tile
         * @return pointer to EnvironmentTile at given position
         */
        EnvironmentTile* getEnvironmentTileAtPosition(int x, int y);
    
    private:
        std::unordered_map<std::pair<int,int>, WorldObject> objects;
        std::unordered_map<std::pair<int,int>, EnvironmentTile> environmentTiles;
        int width;
        int height;
};

#endif