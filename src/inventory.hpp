/**
 * @file inventory.hpp
 * Definition of the Inventory class, a 16-slot inventory and wallet system.
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.hpp"
#include <exception>
#include <list>

class Inventory
{
    public:

        /**
         * Constructs an empty Inventory.
         */
        Inventory();

        /**
         * Returns current amount of funds.
         * 
         * @return current amount of funds
         */
        int getFunds();

        /**
         * Sets current amount of funds to desired value.
         * 
         * @param newAmount new amount of funds
         */
        void setFunds(int newAmount);

        /**
         * Changes current amount of funds by desired value if funds+change > 0 and returns true.
         * Otherwise funds are unchanged, returns false.
         * 
         * @param change amount to change funds by
         * @return true if funds successfully changed, false otherwise
         */
        bool changeFundsBy(int change);
        
        /**
         * Sells held item, removing it from inventory and adding its price to funds.
         * If held item is a tool, no effect.
         */
        void sellHeldItem();

        /**
         * Removes held item from inventory. If held item is a tool, no effect.
         */
        void removeHeldItem();

        /**
         * Returns a pointer to the current held item (nullptr if no current held item).
         * 
         * @return pointer to current held item
         */
        Item* getHeldItem();

        /**
         * Switches held item to adjacent item, circling around if necessary (between indices [-1,7]).
         */
        void swapHeldItem();

        /**
         * Swaps which half of inventory is being viewed.
         */
        void swapInventoryHalf();

        /**
         * Returns true if inventory has at least one space remaining.
         * 
         * @return true if inventory has at least one space remaining, false otherwise.
         */
        bool hasSpace();

        /**
         * If inventory if has space, add item to it and returns true. If inventory is full, returns false.
         * 
         * @param item item to be added
         * @return true only if item successfully added to inventory
         */
        bool addItem(Item item);

        /**
         * Returns inventory's list of items.
         * 
         * @return list of items in inventory
         */
        std::list<Item> getItems();

    private:
        std::list<Item> items;
        int heldItemIndex; // in [-1,7], -1 denoting no held item
        int inventoryHalf; // in [0,1]
        int funds;
};

#endif