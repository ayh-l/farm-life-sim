/**
 * @file item.hpp
 * Definition of the Item class.
 */

#ifndef ITEM_H
#define ITEM_H

#include "worldobject.hpp"
#include "crop.hpp"

class Item : public WorldObject
{
    public:

        /**
         * Constructs an Item with the given details.
         * 
         * @param name name of item
         * @param price price of item when sold
         * @param isTool true if item is a tool (i.e. unable to be sold)
         */
        Item(std::string name, int price, bool isTool);

        /**
         * Constructs an Item from a ripe Crop.
         * 
         * @param ripeCrop crop from which item will be constructed
         */
        Item(Crop ripeCrop);

        /**
         * Return true if item is a tool.
         * 
         * @return true only if item is a tool
         */
        bool isTool();

        /**
         * Returns price of item
         * 
         * @return price of item (for when sold)
         */
        int getPrice();

    private:
        bool tool;
        int price;
};

#endif