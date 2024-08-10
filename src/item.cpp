/**
 * @file item.cpp
 * Implementation of the Item class.
 */

#include "item.hpp"

/**
 * Constructs an Item with the given details.
 * 
 * @param name name of item
 * @param price price of item when sold
 * @param isTool true if item is a tool (i.e. unable to be sold)
 */
Item::Item(std::string name, int price, bool isTool) {
    this->setName(name);
    this->price = price;
    this->tool = isTool;
}

/**
 * Constructs an Item from a ripe Crop.
 * 
 * @param ripeCrop crop from which item will be constructed
 */
Item::Item(Crop ripeCrop) {
    this->setName(ripeCrop.getName());
    this->price = ripeCrop.getFuturePrice();
    this->tool = false;
    
}

/**
 * Return true if item is a tool.
 * 
 * @return true only if item is a tool
 */
bool Item::isTool() {
    return tool;
}

/**
 * Returns price of item
 * 
 * @return price of item (for when sold)
 */
int Item::getPrice() {
    return price;
}