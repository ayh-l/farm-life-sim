#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.hpp"
#include <vector>

class Inventory
{
    //TODO fields
    public:
        Inventory();
        int getFunds();
        void setFunds(int newAmount);
        
        void sellHeldItem(); //not tools though
        Item* getHeldItem();
        void swapHeldItem(); //switches held item to adjacent item (circling around if necessary)

        void addItem(Item item);
        std::vector<Item> getItems();

    private:

};

#endif