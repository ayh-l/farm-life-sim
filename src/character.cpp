/**
 * @file character.hpp
 * Implementation of the Character class.
 */

#include "character.hpp"

/**
 * Constructs a Character with the default name "Luca".
 */
Character::Character() {
    name = "Luca";
}

/**
 * Sets Character's name to given name.
 * 
 * @param name Desired name of Character
 */
void Character::setName(std::string name) {
    this->name = name;
}

/**
 * Returns Character's name.
 * 
 * @return Character's name.
 */
std::string Character::getName() {
    return name;
}