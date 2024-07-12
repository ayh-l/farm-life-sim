#include "environment_tile.hpp"
#include <string>

EnvironmentTile::EnvironmentTile(std::string name, int tilled, int watered, bool walkable, bool fishable) {

}
void EnvironmentTile::till() {

}
void EnvironmentTile::water() {

}
bool EnvironmentTile::walkable() {
    return false; //stub
}
bool EnvironmentTile::fishable() {
    return false; //stub
}
int EnvironmentTile::watered() { // 0-no, 1-yes, 2-not waterable
    return 0; //stub
}
int EnvironmentTile::tilled() { // 0-no, 1-yes, 2-not tillable
    return 0; //stub
}