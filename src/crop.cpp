#include "crop.hpp"

Crop::Crop(std::string name, bool isRipe, int futurePrice) {
    setName(name);
    alive = true;
    daysTillRipe = 10;
    this->futurePrice = futurePrice;
}

void Crop::kill() {
    alive = false;
}

bool Crop::isAlive() {
    return alive;
}

bool Crop::isRipe() {
    return alive && daysTillRipe == 0;
}

int Crop::getFuturePrice() {
    return futurePrice;
}