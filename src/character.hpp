/**
 * @file character.hpp
 * Definition of a Character class, representing the player character.
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{
    public:

        /**
         * Constructs a Character with the default name "Luca".
         */
        Character();

        /**
         * Sets Character's name to given name.
         * 
         * @param name Desired name of Character
         */
        void setName(std::string name);

        /**
         * Returns Character's name.
         * 
         * @return Character's name.
         */
        std::string getName();

    private:
    
        std::string name;
};

#endif