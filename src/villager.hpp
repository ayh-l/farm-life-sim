#ifndef VILLAGER_H
#define VILLAGER_H

#include "worldobject.hpp"
#include "item.hpp"
#include "conversation.hpp"
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>

class Villager : public WorldObject
{
    //TODO fields
    public:
        Villager(std::string name);
        Villager(std::string name, int friendshipPoints, std::vector<Conversation*>* zeroHeartConversations, std::vector<Conversation*>* oneHeartConversations, std::vector<Conversation*>* twoHeartConversations, std::vector<Conversation*>* threeHeartConversations, std::unordered_map<std::string,std::pair<int,Conversation*> >* giftConversations);
        Conversation* talk(Item* item);
        void passDay();
        void changeFriendshipPointsBy(int change);
        void setFriendshipPoints(int points);
        int getFriendshipPoints();

        //for testing purposes only
        std::vector<Conversation*>* getZeroHeartConversations();
        std::vector<Conversation*>* getOneHeartConversations();
        std::vector<Conversation*>* getTwoHeartConversations();
        std::vector<Conversation*>* getThreeHeartConversations();
        std::unordered_map<std::string,std::pair<int,Conversation*> >* getGiftConversations();

    private:
        std::vector<Conversation*>* zeroHeartConversations;   //acquaintance
        std::vector<Conversation*>* oneHeartConversations;    //friend
        std::vector<Conversation*>* twoHeartConversations;    //close friend
        std::vector<Conversation*>* threeHeartConversations;  //best friend
        std::unordered_map<std::string,std::pair<int,Conversation*> >* giftConversations;
        int friendshipPoints; //0-100 points, translates to 0-3 hearts ([0-24],[25-49],[50-74],[75-100])
        bool talkedToToday;
        
};

#endif