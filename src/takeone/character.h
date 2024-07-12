#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include <utility>
#include "item.h"
#include "itemid.h"
#include "map.h"

class Character
{
    public:
        //TODO descriptions for public procedures
        Character();
        
        std::string get_name();

        int get_wallet_funds();
        void edit_wallet_funds(int change);

        std::vector<Item> get_inventory();
        ItemId get_item_held();
        void remove_item_held(); //removes held item, and removes one of it from inventory
        int swap_item_held(); //cycles between the first 8 indices of inventory. 0=hoe, 1=watercan, 2=rod always. returns the new index
        void swap_items_at_positions(int a, int b); //swaps two items in inventory
        void remove_from_inventory(ItemId item_id, int amount);
        void sell(int position, int revenue); //removes inventory item at position, adds revenue (if any) to wallet
        void add_to_inventory(ItemId item_id);

        std::pair<int,int> get_position();
        std::pair<int,int> get_up_position(); //returns pos directly above character
        std::pair<int,int> get_down_position(); //returns pos directly below character
        std::pair<int,int> get_right_position(); //returns pos directly to the right of character
        std::pair<int,int> get_left_position(); //returns pos directly to the left of character
        void change_position(int new_x, int new_y);
        int get_direction_facing();
        void change_direction_facing(int new_direction);

    private:
        std::string name;
        int wallet;
        std::unordered_map<int,int> inventory; // <[item's code], [# of item in inventory]>
        ItemId item_held_id;
        std::pair<int,int> position;
        int direction_facing; //0=north, 1=east, 2=south, 3=west
};

#endif