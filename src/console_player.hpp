/**
 * @file console_player.hpp
 * Definition of the ConsolePlayer class.
 */

#ifndef CONSOLE_PLAYER_H
#define CONSOLE_PLAYER_H

#include "character.hpp"
#include "navigator.hpp"
#include "inventory.hpp"

class ConsolePlayer {

    public:

        /**
         * Constructs a ConsolePlayer.
         */
        ConsolePlayer();

    private:

        /**
         * Initializes character, navigator and inventory.
         */
        void initializeWorld();

        /**
         * Runs through and prints an appropriate villager conversation.
         * 
         * @param villager Pointer to villager with whom to speak.
         */
        void talk(Villager* villager);

        Character character;
        Navigator navigator;
        Inventory inventory;
};

#endif