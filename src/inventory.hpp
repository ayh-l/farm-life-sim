#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.hpp"
#include <exception>
#include <list>

// a simple 16-slot inventory
class Inventory
{
    //TODO fields
    public:
        Inventory();
        int getFunds();
        void setFunds(int newAmount);
        void changeFundsBy(int change); //thows exception if change>funds
        
        void sellHeldItem(); //not tools though
        Item* getHeldItem();
        void swapHeldItem(); //switches held item to adjacent item (circling around if necessary)
        void swapInventoryHalf(); //swaps which half of inventory is being edited/viewed (0-7 or 8-15)

        bool hasSpace();
        void addItem(Item item);
        std::list<Item> getItems();

    private:
        std::list<Item> items;
        int heldItemIndex; //circles around indices 0-7
        int inventoryHalf; //0-1
        int funds;

        class insufficientFundsException : public std::exception
        {
            virtual const char* what() const throw() {
                return "Insufficient funds;";
            }
        } insuffFundsExcp;
};

#endif