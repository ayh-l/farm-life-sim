#include "item.hpp"

Item::Item(std::string name, int price, bool isTool) {
}
Item::Item(Crop ripeCrop) {
}
bool Item::isTool() { //gives true if not a tool
    return false; //TODO stub
}
int Item::getPrice() {
    return 0; //stub TODO
}