/**
 * @file villager.hpp
 * Definition of the Villager class.
 */

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
    public:

        /**
         * Constructs specified Villager.
         * 
         * @param name name of desired Villager to construct (one of "Jo", "Laurie", "Bunny", "Meg")
         */
        Villager(std::string name);

        /**
         * Constructs a Villager with given name, frienship points, and conversation collections.
         * 
         * @param name Villager's name
         * @param friendshipPoints amount friendship points accumulated between player character and Villager
         * @param zeroHeartConversations pointer to vector of pointers to Conversations Villager has at the zero heart friendship level
         * @param oneHeartConversations pointer to vector of pointers to Conversations Villager has at the one heart friendship level
         * @param twoHeartConversations pointer to vector of pointers to Conversations Villager has at the two heart friendship level
         * @param threeHeartConversations pointer to vector of pointers to Conversations Villager has at the three heart friendship level
         * @param giftConversations map of strings (gift item name) to pairs in form of <[friendship point change], [pointer to Villager's response]>
         */
        Villager(std::string name, int friendshipPoints, std::vector<Conversation*>* zeroHeartConversations,
        std::vector<Conversation*>* oneHeartConversations, std::vector<Conversation*>* twoHeartConversations,
        std::vector<Conversation*>* threeHeartConversations, std::unordered_map<std::string,std::pair<int,Conversation*> >* giftConversations);

        /**
         * Returns a pointer to a random conversation within the appropriate heart level conversation vector.
         * If current held item is giftable, changes Villager's friendship points appropriately.
         * 
         * @param item pointer to player character's held item
         * @return pointer to appropriate conversation
         */
        Conversation* talk(Item* item);

        /**
         * To be called on day changes. Increases Villager's friendship points if spoken to today and resets status to not spoken to.
         */
        void passDay();

        /**
         * Changes friendship points by desired amount. If doing so would fall outside [0,100],
         * stops decreasing or increasing at 0 or 100, respectively.
         * 
         * @param change desired amount to change friendship points by
         */
        void changeFriendshipPointsBy(int change);

        /**
         * Sets friendship points as desired, rounding to the closest in {0,100} if outside [0,100].
         * 
         * @param change desired amount of friendship points
         */
        void setFriendshipPoints(int points);

        /**
         * Returns current amount of friendship points
         * 
         * @return Villager's current amount of friendship points with player character
         */
        int getFriendshipPoints();

        /**
         * For testing purposes only. Returns true if Villager has been spoken to today
         * 
         * @return true only if Villager has been spoken to today
         */
        bool didTalkToToday();

        /**
         * For testing purposes only. Returns pointer to map of map of strings (gift item name) to pairs in form of
         * <[friendship point change], [pointer to Villager's response]>.
         * 
         * @return pointer to map of strings (gift item name) to pairs representing villager response information
         */
        std::vector<Conversation*>* getZeroHeartConversations();

        /**
         * For testing purposes only. Returns pointer to vector of Villager's zero heart level conversations.
         * 
         * @return pointer to vector of pointers to Villager's zero heart level conversations
         */
        std::vector<Conversation*>* getOneHeartConversations();

        /**
         * For testing purposes only. Returns pointer to vector of Villager's one heart level conversations.
         * 
         * @return pointer to vector of pointers to Villager's one heart level conversations
         */
        std::vector<Conversation*>* getTwoHeartConversations();

        /**
         * For testing purposes only. Returns pointer to vector of Villager's two heart level conversations.
         * 
         * @return pointer to vector of pointers to Villager's two heart level conversations
         */
        std::vector<Conversation*>* getThreeHeartConversations();

        /**
         * For testing purposes only. Returns pointer to vector of Villager's three heart level conversations.
         * 
         * @return pointer to vector of pointers to Villager's three heart level conversations
         */
        std::unordered_map<std::string,std::pair<int,Conversation*> >* getGiftConversations();

    private:
        std::vector<Conversation*>* zeroHeartConversations;   //acquaintance
        std::vector<Conversation*>* oneHeartConversations;    //friend
        std::vector<Conversation*>* twoHeartConversations;    //close friend
        std::vector<Conversation*>* threeHeartConversations;  //best friend
        std::unordered_map<std::string,std::pair<int,Conversation*> >* giftConversations;
        int friendshipPoints; //0-100 points, translates to 0-3 hearts ([0-24],[25-49],[50-74],[75-100])
        bool talkedToToday; //increases friend points by 10 daily
        
};

#endif