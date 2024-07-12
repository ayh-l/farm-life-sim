#ifndef VILLAGER_H
#define VILLAGER_H

#include "worldobject.hpp"
#include "item.hpp"
#include "conversation.hpp"
#include <string>
#include <vector>

class Villager : public WorldObject
{
    //TODO fields
    public:
        Conversation* talk(Item* item, std::string yourName);
        void passDay();

    private:
        std::vector<Conversation*> convoList;
        int friendshipLevel;
};

#endif