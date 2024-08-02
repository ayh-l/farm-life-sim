#include "character.hpp"

Character::Character() { //default name is "Luca"
    name = "Luca";
}

void Character::setName(std::string name) {
    this->name = name;
}

std::string Character::getName() {
    return name;
}