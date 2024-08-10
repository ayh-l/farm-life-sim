/**
 * @file environment_tile.hpp
 * Definition of the EnvironmentTile class, representing an immoveable environment tile of a Map.
 */

#ifndef ENVIRONMENT_TILE_H
#define ENVIRONMENT_TILE_H

#include <string>
#include <tuple>
#include <optional>

class EnvironmentTile
{
    public:

        /**
         * Constructs an EnvironmentTile with the given values.
         * 
         * @param name name of EnvironmentTile
         * @param tilled integer in [0,2] where 0: not tilled, 1: tilled, 2: not tillable
         * @param watered integer in [0,2] where 0: not watered, 1: watered, 2: not waterable
         * @param walkable true when EnvironmentTile may be walked on
         * @param fishable true when EnvironmentTile may be fished on
         */
        EnvironmentTile(std::string name, int tilled, int watered, bool walkable, bool fishable);

        /**
         * Constructs an EnvironmentTile with the given values.
         * 
         * @param name name of EnvironmentTile
         * @param tilled integer in [0,2] where 0: not tilled, 1: tilled, 2: not tillable
         * @param watered integer in [0,2] where 0: not watered, 1: watered, 2: not waterable
         * @param walkable true when EnvironmentTile may be walked on
         * @param fishable true when EnvironmentTile may be fished on
         * @param pathTo for EnvironmentTiles which lead to other maps. Resepective elements in tuple represent:
         *                  - direction of path, one of 'n', 'e', 's', 'w' (representing cardinal directions)
         *                  - the next map as an index (0: farm, 1: town, 2: forest, 3: home, 4: house1, 5: house2, 6: stumphouse)
         *                  - x position on the new map
         *                  - y position on the new map
         */
        EnvironmentTile(std::string name, int tilled, int watered, bool walkable, bool fishable, std::tuple<char,int,int,int> pathTo);

        /**
         * Tills EnvironmentTile, setting its status as "tilled", unless it is not tillable.
         */
        void till();

        /**
         * Waters EnvironmentTile, setting its status as "watered", unless it is not waterable.
         */
        void water();

        /**
         * Returns true if EnvironmentTile may be walked on.
         * 
         * @return true only if EnvironmentTile may be walked on.
         */
        bool isWalkable();

        /**
         * Returns true if EnvironmentTile may be fished on.
         * 
         * @return true only if EnvironmentTile may be fished on.
         */
        bool isFishable();

        /**
         * Returns true if EnvironmentTile is watered.
         * 
         * @return true only if EnvironmentTile is watered.
         */
        bool isWatered();

        /**
         * Returns true if EnvironmentTile is tilled.
         * 
         * @return true only if EnvironmentTile is tilled.
         */
        bool isTilled();

        /**
         * Returns true if EnvironmentTile is a path (ie. leads to another map if player departs from EnvironmentTile in a certain direction).
         * 
         * @return true only if EnvironmentTile is a path.
         */
        bool isPath();

        /**
         * Returns direction of path contained in this EnvironmentTile. If this is not a path, returns default value 'o'.
         * 
         * @return direction of path (one of cardinal directions 'n', 'e', 's', 'w') contained in EnvironmentTile. If none, returns 'o'.
         */
        char directionOfPath();

        /**
         * Returns integer map id of the map which this EnvironmentTile's path leads to. If this is not a path, returns default value -1.
         * 
         * @return integer map id of map which EnvironmentTile leads to
         */
        int pathLeadsToMapId();

        /**
         * Returns integer pair representing new position on new map which EnvironmentTile's path leads to.
         * 
         * @return integer pair representing new position on new map which EnvironmentTile leads to
         */
        std::pair<int,int> pathLeadsToPosition();

        /**
         * Returns name of EnvironmentTile.
         * 
         * @return name of EnvironmentTile.
         */
        std::string getName();

    private:
        int watered; // 0-no, 1-yes, 2-not waterable
        int tilled; // 0-no, 1-yes, 2-not waterable
        bool walkable;
        bool fishable;
        std::optional<std::tuple<char,int,int,int> > pathTo; // < direction of path , mapId , xpos on map given by mapId , ypos on map given by mapId >
        std::string name;
};

#endif