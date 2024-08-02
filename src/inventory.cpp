#include "inventory.hpp"

Inventory::Inventory() {
    funds = 0;
    heldItemIndex = -1;
    inventoryHalf = 0;
}

int Inventory::getFunds() {
    return funds;
}

void Inventory::setFunds(int newAmount) {
    funds = newAmount;
}

void Inventory::changeFundsBy(int change) {
    if (change < 0 && abs(change) > funds)
        throw insuffFundsExcp;
    funds = funds + change;
}

void Inventory::sellHeldItem() { //not tools though
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

Item* Inventory::getHeldItem() {
    if (heldItemIndex == -1 || heldItemIndex + inventoryHalf*8 >= static_cast<int>(items.size()))
        return nullptr;
    auto iterator = items.begin();
    for (int i = 0; i < heldItemIndex + inventoryHalf*8; i++)
        iterator++;
    Item* heldItem = &(*iterator);
    return heldItem;
}

void Inventory::swapHeldItem() { //switches held item to adjacent item (circling around if necessary)
    if (heldItemIndex == 7) {
        heldItemIndex = -1;
    } else {
        heldItemIndex++;
    }
}

void Inventory::swapInventoryHalf() {
    inventoryHalf = (inventoryHalf + 1) % 2;
}

bool Inventory::hasSpace() {
    return items.size() < 16;
}

void Inventory::addItem(Item item) { //TODO change to bool? (successful)
    if (hasSpace())
        items.push_back(item);
}

std::list<Item> Inventory::getItems() {
    return items;
}