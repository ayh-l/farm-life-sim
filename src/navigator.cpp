#include "navigator.hpp"
#include <utility>

Navigator::Navigator(std::string currentMap, int xPos, int yPos, char directionFacing) {

}

Villager* Navigator::interact(Item* heldItem) {
    return nullptr; //TODO stub
}
void Navigator::walk(char direction) { //one of 'n','e','s','w'

}
void Navigator::passDayUpdateMaps() {

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
// EnvironmentTile* Navigator::getEnvTileFacing();

void Navigator::removeWorldObjectAtPosition(std::pair<int,int> position) {

}
void Navigator::addWorldObjectAtPosition(std::pair<int,int> position, WorldObject worldObject) {

}
WorldObject Navigator::getWorldObjectAtPosition(std::pair<int,int> position) {
    return WorldObject(); //TODO stub
}