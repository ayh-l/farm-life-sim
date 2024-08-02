#include "villager.hpp"
#include <utility>
#include <algorithm>

Villager::Villager(std::string name, int friendshipPoints, std::vector<Conversation*>* zeroHeartConversations, std::vector<Conversation*>* oneHeartConversations, std::vector<Conversation*>* twoHeartConversations, std::vector<Conversation*>* threeHeartConversations, std::unordered_map<std::string,std::pair<int,Conversation*> >* giftConversations) {
    this->setName(name);
    this->friendshipPoints = friendshipPoints;
    this->zeroHeartConversations = zeroHeartConversations;
    this->oneHeartConversations = oneHeartConversations;
    this->twoHeartConversations = twoHeartConversations;
    this->threeHeartConversations = threeHeartConversations;
    this->giftConversations = giftConversations;
}

Conversation* Villager::talk(Item* item) {
    if (item == nullptr) {
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

void Villager::passDay() {
    if (talkedToToday)
        changeFriendshipPointsBy(10);
}

void Villager::changeFriendshipPointsBy(int change) {
    if (change >= 0) {
        friendshipPoints = std::min(friendshipPoints + change, 100);
    } else {
        friendshipPoints = std::max(friendshipPoints + change, 0);
    }
}

void Villager::setFriendshipPoints(int points) {
    friendshipPoints = points;
}

int Villager::getFriendshipPoints() {
    return friendshipPoints;
}

std::vector<Conversation*>* Villager::getZeroHeartConversations() {
    return zeroHeartConversations;
}

std::vector<Conversation*>* Villager::getOneHeartConversations() {
    return oneHeartConversations;
}

std::vector<Conversation*>* Villager::getTwoHeartConversations() {
    return twoHeartConversations;
}

std::vector<Conversation*>* Villager::getThreeHeartConversations() {
    return threeHeartConversations;
}

std::unordered_map<std::string,std::pair<int,Conversation*> >* Villager::getGiftConversations() {
    return giftConversations;
}