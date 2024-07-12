#ifndef CONSOLE_PLAYER_H
#define CONSOLE_PLAYER_H

#include <unordered_map>
#include "map.h"
#include "character.h"

class ConsolePlayer {

    public:
        ConsolePlayer();

    private:
        Character character;
        std::vector<Map> maps;
        int current_map; //current map is maps[current_map]
        std::unordered_map<std::string,Item> item_directory; //"[i/c/t/v][#]"
        
        void interact(); //performs suitable action (talk, pick up, travel, etc.) depending on character's position and direction, updating character and current map as necessary
        void initialize_world();
        void initialize_item_directory();
        void pass_day();
};

#endif