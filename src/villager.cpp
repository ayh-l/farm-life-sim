/**
 * @file villager.cpp
 * Implementation of the Villager class.
 */

#include "villager.hpp"
#include <utility>
#include <algorithm>

/**
 * Constructs specified Villager.
 * 
 * @param name name of desired Villager to construct (one of "Jo", "Laurie", "Bunny", "Meg")
 */
Villager::Villager(std::string name) {
    //TODO
}

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
Villager::Villager(std::string name, int friendshipPoints, std::vector<Conversation*>* zeroHeartConversations,
std::vector<Conversation*>* oneHeartConversations, std::vector<Conversation*>* twoHeartConversations,
std::vector<Conversation*>* threeHeartConversations, std::unordered_map<std::string,std::pair<int,Conversation*> >* giftConversations) {
    this->setName(name);
    this->friendshipPoints = friendshipPoints;
    this->zeroHeartConversations = zeroHeartConversations;
    this->oneHeartConversations = oneHeartConversations;
    this->twoHeartConversations = twoHeartConversations;
    this->threeHeartConversations = threeHeartConversations;
    this->giftConversations = giftConversations;
}

/**
 * Returns a pointer to a random conversation within the appropriate heart level conversation vector.
 * If current held item is giftable, changes Villager's friendship points appropriately.
 * 
 * @param item pointer to player character's held item
 * @return pointer to appropriate conversation
 */
Conversation* Villager::talk(Item* item) {
    if (item == nullptr || item->isTool()) {
        std::vector<Conversation*>* conversations;
        if (0 <= friendshipPoints && friendshipPoints < 25)
            conversations = zeroHeartConversations;
        if (25 <= friendshipPoints && friendshipPoints < 50)
            conversations = oneHeartConversations;
        if (50 <= friendshipPoints && friendshipPoints < 75)
            conversations = twoHeartConversations;
        if (75 <= friendshipPoints && friendshipPoints <= 100)
            conversations = threeHeartConversations;
        return (*conversations)[rand() % conversations->size()];
    }

    auto search = giftConversations->find(item->getName());
    if (search == giftConversations->end()) {
        auto defaultResponse = giftConversations->find("default");
        int friendshipPoints = defaultResponse->second.first;
        Conversation* defaultMessage = defaultResponse->second.second;
        changeFriendshipPointsBy(friendshipPoints);
        return defaultMessage;
    }
    int friendshipPoints = search->second.first;
    Conversation* message = search->second.second;
    changeFriendshipPointsBy(friendshipPoints);
    return message;
}

/**
 * To be called on day changes. Increases Villager's friendship points if spoken to today and resets status to not spoken to.
 */
void Villager::passDay() {
    if (talkedToToday)
        changeFriendshipPointsBy(10);
    talkedToToday = false;
}

/**
 * Changes friendship points by desired amount. If doing so would fall outside [0,100],
 * stops decreasing or increasing at 0 or 100, respectively.
 * 
 * @param change desired amount to change friendship points by
 */
void Villager::changeFriendshipPointsBy(int change) {
    if (change >= 0) {
        friendshipPoints = std::min(friendshipPoints + change, 100);
    } else {
        friendshipPoints = std::max(friendshipPoints + change, 0);
    }
}

/**
 * Sets friendship points as desired, rounding to the closest in {0,100} if outside [0,100].
 * 
 * @param change desired amount of friendship points
 */
void Villager::setFriendshipPoints(int points) {
    friendshipPoints = points;
    if (points < 0)
        friendshipPoints = 0;
    if (points > 100)
        friendshipPoints = 100;
}

/**
 * Returns current amount of friendship points
 * 
 * @return Villager's current amount of friendship points with player character
 */
int Villager::getFriendshipPoints() {
    return friendshipPoints;
}

/**
 * For testing purposes only. Returns true if Villager has been spoken to today
 * 
 * @return true only if Villager has been spoken to today
 */
bool Villager::didTalkToToday() {
    return talkedToToday;
}

/**
 * For testing purposes only. Returns pointer to vector of Villager's zero heart level conversations.
 * 
 * @return pointer to vector of pointers to Villager's zero heart level conversations
 */
std::vector<Conversation*>* Villager::getZeroHeartConversations() {
    return zeroHeartConversations;
}

/**
 * For testing purposes only. Returns pointer to vector of Villager's one heart level conversations.
 * 
 * @return pointer to vector of pointers to Villager's one heart level conversations
 */
std::vector<Conversation*>* Villager::getOneHeartConversations() {
    return oneHeartConversations;
}

/**
 * For testing purposes only. Returns pointer to vector of Villager's two heart level conversations.
 * 
 * @return pointer to vector of pointers to Villager's two heart level conversations
 */
std::vector<Conversation*>* Villager::getTwoHeartConversations() {
    return twoHeartConversations;
}

/**
 * For testing purposes only. Returns pointer to vector of Villager's three heart level conversations.
 * 
 * @return pointer to vector of pointers to Villager's three heart level conversations
 */
std::vector<Conversation*>* Villager::getThreeHeartConversations() {
    return threeHeartConversations;
}

/**
 * For testing purposes only. Returns pointer to map of map of strings (gift item name) to pairs in form of
 * <[friendship point change], [pointer to Villager's response]>.
 * 
 * @return pointer to map of strings (gift item name) to pairs representing villager response information
 */
std::unordered_map<std::string,std::pair<int,Conversation*> >* Villager::getGiftConversations() {
    return giftConversations;
}