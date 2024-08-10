/**
 * @file worldobject.cpp
 * Implementation of the WorldObject class.
 */

#include "worldobject.hpp"

/**
 * Constructs a WorldObject with default name.
 */
WorldObject::WorldObject() {
    name = "unnamed object";
}

/**
 * Sets name of WorldObject as specified.
 * 
 * @param name desired name of WorldObject
 */
void WorldObject::setName(std::string name) {
    this->name = name;
}

/**
 * Returns name of WorldObject
 * 
 * @return name of WorldObject
 */
std::string WorldObject::getName() {
    return name;
}