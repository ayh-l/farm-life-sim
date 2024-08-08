#include "navigator.hpp"
#include <utility>

Navigator::Navigator() {
    //TODO initialize maps vector
}

Navigator::Navigator(int currentMap, int xPos, int yPos, char directionFacing) {

}

WorldObject* Navigator::interact(Item* heldItem) {
    return nullptr; //TODO stub
}
void Navigator::walk(char direction) { //one of 'n','e','s','w'

}

/**
 * Appropriately updates villagers, crops and items for the next in-game day.
 * 
 * If a villager has been spoken to today, their friendship points increase by 5.
 * If a crop is on watered soil, the crop remains alive (and possibly ripens into an item), and otherwise is killed.
 * Any respawning items that have been collected are replaced.
 */
void Navigator::passDayUpdateMaps() {

}

void Navigator::changeCurrentMapTo(int mapId) {

}

//for testing purposes / console version? / maybe art needs it too...
std::pair<int,int> Navigator::getPosition() {
    return std::make_pair(0,0); //TODO stub
}
char Navigator::getDirectionFacing() {
    return 'n'; //TODO stub
}
WorldObject* Navigator::getObjectFacing() {
    return nullptr; //TODO stub
}
void Navigator::removeObjectFacing() {
    
}
EnvironmentTile* Navigator::getEnvTileFacing() {

}