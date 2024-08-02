#include "worldobject.hpp"

WorldObject::WorldObject() {
    
}

void WorldObject::setName(std::string name) {
    this->name = name;
}

std::string WorldObject::getName() {
    return name;
}