/**
 * @file character.hpp
 * Definition of the Crop class.
 */

#ifndef CROP_H
#define CROP_H

#include "worldobject.hpp"

class Crop : public WorldObject
{
    public:

        /**
         * Constructs a Crop with the given details.
         * 
         * @param name Name of Crop
         * @param futurePrice price of Crop after it ripens and turns into an Item
         */
        Crop(std::string name, int futurePrice);

        /**
         * Kills crop so that it can no longer grow / become ripe.
         */
        void kill();

        /**
         * Returns price of ripe Crop.
         * 
         * @return Price of ripe Crop.
         */
        int getFuturePrice();

        /**
         * Returns true if Crop is alive.
         * 
         * @return true if Crop is alive.
         */
        bool isAlive();

        /**
         * Sets days until crop is ripe to given value.
         * 
         * @param daysTillRipe Desired number of days until crop is ripe.
         */
        void setDaysTillRipe(int daysTillRipe);

        /**
         * Returns days until crop is ripe.
         * 
         * @return Number of days until crop is ripe.
         */
        int getDaysTillRipe();

    private:
        bool wateredToday;
        int daysTillRipe; //-1 if dead
        int futurePrice;
};

#endif