#include "item.hpp"

Item::Item(std::string name, int price, bool isTool) {
    this->setName(name);
    this->price = price;
    this->tool = isTool;
}

Item::Item(Crop ripeCrop) {
    this->setName(ripeCrop.getName());
    this->price = ripeCrop.getFuturePrice();
    this->tool = false;
    
}
bool Item::isTool() { //gives true if tool
    return tool;
}
int Item::getPrice() {
    return price;
}