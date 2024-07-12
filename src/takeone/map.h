#ifndef MAP_H
#define MAP_H

#include <unordered_map>
#include <utility>
#include <string>
#include "item.h"
#include "itemid.h"

class Map
{
    public:
        Map(std::string type); //initializes map according to type
        bool check_pos(std::pair<int,int> pos); //returns true if there is an item at the given position
        ItemId* get_item_id_at_pos(std::pair<int,int> pos); //if there is an item at the given position, returns its id
        void remove_item_at_pos(std::pair<int,int> pos); //if there is an item at the given position, removes it
        void place_item_at_pos(std::pair<int,int> pos, ItemId item_id); //places itm at pos, replacing any item that was there
        std::pair<int,int> move(int direction, std::pair<int,int> current_position); //0=north, 1=east, 2=south, 3=west. returns new position. if leads to a different map, returns ([entrance_id, an int<0], [map_id])
        std::pair<int,int> get_entrance_position(int index);

    private:
        // void init_farm_map(); //TODO special because have to also consider player's placement of things
        void init_town_map();
        void init_forest_map();
        void init_house0();
        void init_house1();
        void init_house2();
        void init_house3();
        void init_house4();
        void init_by_string(std::string legend);

        std::vector<std::pair<int,int>> entrance_positions; // -index = index_id returned in move
        std::unordered_map<std::pair<int,int>, ItemId> item_positions; //pos and id
        std::string name;
};

#endif