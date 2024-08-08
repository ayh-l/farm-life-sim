#include "crop.hpp"

Crop::Crop(std::string name, int futurePrice) {
    setName(name);
    daysTillRipe = 10;
    this->futurePrice = futurePrice;
}

void Crop::kill() {
    daysTillRipe = -1;
}

bool Crop::isAlive() {
    return daysTillRipe > -1;
}

int Crop::getFuturePrice() {
    return futurePrice;
}