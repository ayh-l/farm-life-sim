/**
 * @file inventory.cpp
 * Implementation of the Inventory class, a 16-slot inventory and wallet system.
 */

#include "inventory.hpp"

/**
 * Constructs an empty Inventory.
 */
Inventory::Inventory() {
    funds = 0;
    heldItemIndex = -1;
    inventoryHalf = 0;
}

/**
 * Returns current amount of funds.
 * 
 * @return current amount of funds
 */
int Inventory::getFunds() {
    return funds;
}

/**
 * Sets current amount of funds to desired value.
 * 
 * @param newAmount new amount of funds
 */
void Inventory::setFunds(int newAmount) {
    funds = newAmount;
}

/**
 * Changes current amount of funds by desired value if funds+change > 0 and returns true.
 * Otherwise funds are unchanged, returns false.
 * 
 * @param change amount to change funds by
 * @return true if funds successfully changed, false otherwise
 */
bool Inventory::changeFundsBy(int change) {
    if (change < 0 && abs(change) > funds)
        return false;
    funds = funds + change;
    return true;
}

/**
 * Sells held item, removing it from inventory and adding its price to funds.
 * If held item is a tool, no effect.
 */
void Inventory::sellHeldItem() {
    if (heldItemIndex == -1 || heldItemIndex + inventoryHalf*8 >= static_cast<int>(items.size()))
        return;
    auto iterator = items.begin();
    for (int i = 0; i < heldItemIndex + inventoryHalf*8; i++)
        iterator++;
    if (iterator->isTool())
        return;
    changeFundsBy(iterator->getPrice());
    items.erase(iterator);
}

/**
 * Removes held item from inventory. If held item is a tool, no effect.
 */
void Inventory::removeHeldItem() {
    if (heldItemIndex == -1 || heldItemIndex + inventoryHalf*8 >= static_cast<int>(items.size()))
        return;
    auto iterator = items.begin();
    for (int i = 0; i < heldItemIndex + inventoryHalf*8; i++)
        iterator++;
    if (iterator->isTool())
        return;
    items.erase(iterator);
}

/**
 * Returns a pointer to the current held item (nullptr if no current held item).
 * 
 * @return pointer to current held item
 */
Item* Inventory::getHeldItem() {
    if (heldItemIndex == -1 || heldItemIndex + inventoryHalf*8 >= static_cast<int>(items.size()))
        return nullptr;
    auto iterator = items.begin();
    for (int i = 0; i < heldItemIndex + inventoryHalf*8; i++)
        iterator++;
    Item* heldItem = &(*iterator);
    return heldItem;
}

/**
 * Switches held item to adjacent item, circling around if necessary (between indices [-1,7]).
 */
void Inventory::swapHeldItem() { //switches held item to adjacent item (circling around if necessary)
    if (heldItemIndex == 7) {
        heldItemIndex = -1;
    } else {
        heldItemIndex++;
    }
}

/**
 * Swaps which half of inventory is being viewed.
 */
void Inventory::swapInventoryHalf() {
    inventoryHalf = (inventoryHalf + 1) % 2;
}

/**
 * Returns true if inventory has at least one space remaining.
 * 
 * @return true if inventory has at least one space remaining, false otherwise.
 */
bool Inventory::hasSpace() {
    return items.size() < 16;
}

/**
 * If inventory if has space, add item to it and returns true. If inventory is full, returns false.
 * 
 * @param item item to be added
 * @return true only if item successfully added to inventory
 */
bool Inventory::addItem(Item item) {
    if (hasSpace()) {
        items.push_back(item);
        return true;
    }
    return false;
}

/**
 * Returns inventory's list of items.
 * 
 * @return list of items in inventory
 */
std::list<Item> Inventory::getItems() {
    return items;
}