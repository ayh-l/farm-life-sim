#include "villager.hpp"
#include <utility>

Villager::Villager(std::string name, int friendshipPoints, std::vector<Conversation*>* zeroHeartConversations, std::vector<Conversation*>* oneHeartConversations, std::vector<Conversation*>* twoHeartConversations, std::vector<Conversation*>* threeHeartConversations, std::unordered_map<std::string,std::pair<int,Conversation*>>* giftConversations) {
    
}

Conversation* Villager::talk(Item* item) {
    return nullptr; //TODO stub
}

void Villager::passDay() {
    
}

void Villager::changeFriendshipPointsBy(int change) {

}
void Villager::setFriendshipPoints(int points) {

}
int Villager::getFriendshipPoints() {
    return 0; //stub TODO
}

std::vector<Conversation*>* Villager::getZeroHeartConversations() {
    return {}; //stub TODO
}
std::vector<Conversation*>* Villager::getOneHeartConversations() {
    return {}; //stub TODO
}
std::vector<Conversation*>* Villager::getTwoHeartConversations() {
    return {}; //stub TODO
}
std::vector<Conversation*>* Villager::getThreeHeartConversations() {
    return {}; //stub TODO
}
std::unordered_map<Item,std::pair<int,Conversation*>>* Villager::getGiftConversations() {
    return nullptr; //stub TODO
}