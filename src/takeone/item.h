#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
    public:
        Item(std::string type);
        std::string get_item_name();
        std::string get_item_msg();
        bool can_pickup();
        bool can_walk_over();
        bool can_gift();

    private:
        std::string name;
        std::string msg; //null if no message or it's an object to be picked up
        bool pickupable;
        bool walkable;
        bool giftable;
        //TODO item's image
};

#endif