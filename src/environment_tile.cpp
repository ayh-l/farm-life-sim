/**
 * @file environment_tile.cpp
 * Implementation of the EnvironmentTile class.
 */

#include "environment_tile.hpp"
#include <string>

/**
 * Constructs an EnvironmentTile with the given values.
 * 
 * @param name name of EnvironmentTile
 * @param tilled integer in [0,2] where 0: not tilled, 1: tilled, 2: not tillable
 * @param watered integer in [0,2] where 0: not watered, 1: watered, 2: not waterable
 * @param walkable true when EnvironmentTile may be walked on
 * @param fishable true when EnvironmentTile may be fished on
 */
EnvironmentTile::EnvironmentTile(std::string name, int tilled, int watered, bool walkable, bool fishable) {
    this->name = name;
    this->tilled = tilled;
    this->watered = watered;
    this->walkable = walkable;
    this->fishable = fishable;
}

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
EnvironmentTile::EnvironmentTile(std::string name, int tilled, int watered, bool walkable, bool fishable, std::tuple<char,int,int,int> pathTo) {
    EnvironmentTile(name, tilled, watered, walkable, fishable);
    this->pathTo = pathTo;
}

/**
 * Tills EnvironmentTile, setting its status as "tilled", unless it is not tillable.
 */
void EnvironmentTile::till() {
    if (tilled == 2)
        return;
    tilled = 1;
}

/**
 * Waters EnvironmentTile, setting its status as "watered", unless it is not waterable.
 */
void EnvironmentTile::water() {
    if (watered == 2)
        return;
    watered = 1;
}

/**
 * Returns true if EnvironmentTile may be walked on.
 * 
 * @return true only if EnvironmentTile may be walked on.
 */
bool EnvironmentTile::isWalkable() {
    return walkable;
}

/**
 * Returns true if EnvironmentTile may be fished on.
 * 
 * @return true only if EnvironmentTile may be fished on.
 */
bool EnvironmentTile::isFishable() {
    return fishable;
}

/**
 * Returns true if EnvironmentTile is watered.
 * 
 * @return true only if EnvironmentTile is watered.
 */
bool EnvironmentTile::isWatered() {
    return watered == 1;
}

/**
 * Returns true if EnvironmentTile is tilled.
 * 
 * @return true only if EnvironmentTile is tilled.
 */
bool EnvironmentTile::isTilled() {
    return tilled == 1;
}

/**
 * Returns true if EnvironmentTile is a path (ie. leads to another map if player departs from EnvironmentTile in a certain direction).
 * 
 * @return true only if EnvironmentTile is a path.
 */
bool EnvironmentTile::isPath() {
    return pathTo.has_value();
}

/**
 * Returns direction of path contained in this EnvironmentTile. If this is not a path, returns default value 'o'.
 * 
 * @return direction of path (one of cardinal directions 'n', 'e', 's', 'w') contained in EnvironmentTile. If none, returns 'o'.
 */
char EnvironmentTile::directionOfPath() {
    if (!isPath())
        return 'o';
    return std::get<0>(pathTo.value());
}

/**
 * Returns integer map id of the map which this EnvironmentTile's path leads to. If this is not a path, returns default value -1.
 * 
 * @return integer map id of map which EnvironmentTile leads to
 */
int EnvironmentTile::pathLeadsToMapId() {
    if (!isPath())
        return -1;
    return std::get<1>(pathTo.value());
}

/**
 * Returns integer pair representing new position on new map which EnvironmentTile's path leads to.
 * 
 * @return integer pair representing new position on new map which EnvironmentTile leads to
 */
std::pair<int,int> EnvironmentTile::pathLeadsToPosition() {
    if (!isPath())
        return {-1,-1};
    return {std::get<2>(pathTo.value()), std::get<3>(pathTo.value())};
}

/**
 * Returns name of EnvironmentTile.
 * 
 * @return name of EnvironmentTile.
 */
std::string EnvironmentTile::getName() {
    return name;
}