#ifndef VILLAGER_H
#define VILLAGER_H

#include <string>
#include "item.h"

class Villager : public Item
{
    public:
        Villager(std::string type);
        void talk();
        void gift(ItemId item_id);

    private:
        std::string msgs[35]; //0-9 are acquaintance msgs, 10-19 are friend msgs, 20-29 are special msgs, 30-34 are item received msgs
        int todays_msg; //index of today's chosen message
        int friendship_level;
        bool talked_to_today;
        //TODO villager's images
};

#endif