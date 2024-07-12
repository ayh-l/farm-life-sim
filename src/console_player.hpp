#ifndef CONSOLE_PLAYER_H
#define CONSOLE_PLAYER_H

#include "character.hpp"
#include "navigator.hpp"
#include "inventory.hpp"

class ConsolePlayer {

    public:
        ConsolePlayer();

    private:
        void initializeWorld();
        void passDay();
        void interact();
        void talk(Villager* villager);
        Character character;
        Navigator navigator;
        Inventory inventory;
};

#endif