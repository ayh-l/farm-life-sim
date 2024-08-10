/**
 * @file conversation.cpp
 * Implementation of the Crop class.
 */

#include "crop.hpp"

/**
 * Constructs a Crop with the given details.
 * 
 * @param name Name of Crop
 * @param futurePrice price of Crop after it ripens and turns into an Item
 */
Crop::Crop(std::string name, int futurePrice) {
    setName(name);
    daysTillRipe = 10;
    this->futurePrice = futurePrice;
}

/**
 * Kills crop so that it can no longer grow / become ripe.
 */
void Crop::kill() {
    daysTillRipe = -1;
}

/**
 * Returns true if Crop is alive.
 * 
 * @return true if Crop is alive.
 */
bool Crop::isAlive() {
    return daysTillRipe > -1;
}

/**
 * Returns price of ripe Crop.
 * 
 * @return Price of ripe Crop.
 */
int Crop::getFuturePrice() {
    return futurePrice;
}

/**
 * Sets days until crop is ripe to given value.
 * 
 * @param daysTillRipe Desired number of days until crop is ripe.
 */
void Crop::setDaysTillRipe(int daysTillRipe) {
    this->daysTillRipe = daysTillRipe;
}

/**
 * Returns days until crop is ripe.
 * 
 * @return Number of days until crop is ripe.
 */
int Crop::getDaysTillRipe() {
    return daysTillRipe;
}