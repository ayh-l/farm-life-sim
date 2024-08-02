#ifndef ITEM_H
#define ITEM_H

#include "worldobject.hpp"
#include "crop.hpp"

class Item : public WorldObject
{
    //TODO fields
    public:
        Item(std::string name, int price, bool isTool);
        Item(Crop ripeCrop);
        bool isTool(); //item is removeable if not a tool
        int getPrice();

    private:
        bool tool;
        int price;
};

#endif