#include "environment_tile.hpp"
#include <string>

EnvironmentTile::EnvironmentTile(std::string name, int tilled, int watered, bool walkable, bool fishable) {
    this->name = name;
    this->tilled = tilled;
    this->watered = watered;
    this->walkable = walkable;
    this->fishable = fishable;
}

void EnvironmentTile::till() {
    if (tilled == 2)
        return;
    tilled = 1;
}

void EnvironmentTile::water() {
    if (watered == 2)
        return;
    watered = 1;
}

bool EnvironmentTile::isWalkable() {
    return walkable;
}

bool EnvironmentTile::isFishable() {
    return fishable;
}

bool EnvironmentTile::isWatered() {
    return watered == 1;
}

bool EnvironmentTile::isTilled() {
    return tilled == 1;
}

std::string EnvironmentTile::getName() {
    return name;
}