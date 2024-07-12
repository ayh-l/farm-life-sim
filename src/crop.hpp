#ifndef CROP_H
#define CROP_H

#include "worldobject.hpp"

class Crop : public WorldObject
{
    //TODO image setting function (ripe, unripe, dead)
    //TODO fields
    public:
        Crop(std::string name, bool isRipe, int futurePrice);
        void kill();
        int getFuturePrice();
        bool isAlive();
        bool isRipe(); //is true right before it gets turned into an Item (during passday)

    private:
};

#endif