#include "environment_tile.hpp"
#include <string>

EnvironmentTile::EnvironmentTile(std::string name, int tilled, int watered, bool walkable, bool fishable) {
    this->name = name;
    this->tilled = tilled;
    this->watered = watered;
    this->walkable = walkable;
    this->fishable = fishable;
}

EnvironmentTile::EnvironmentTile(std::string name, int tilled, int watered, bool walkable, bool fishable, std::tuple<char,int,int,int> pathTo) {
    EnvironmentTile(name, tilled, watered, walkable, fishable);
    this->pathTo = pathTo;
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

bool EnvironmentTile::isPath() {
    return pathTo.has_value();
}

char EnvironmentTile::directionOfPath() {
    if (!isPath())
        return 'o';
    return std::get<0>(pathTo.value());
}

int EnvironmentTile::pathLeadsToMapId() {
    if (!isPath())
        return -1;
    return std::get<1>(pathTo.value());
}

std::pair<int,int> EnvironmentTile::pathLeadsToPosition() {
    if (!isPath())
        return {-1,-1};
    return {std::get<2>(pathTo.value()), std::get<3>(pathTo.value())};
}

std::string EnvironmentTile::getName() {
    return name;
}