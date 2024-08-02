#include "question.hpp"
#include <utility>

Question::Question(std::string message, std::vector<std::tuple<std::string, int, Conversation*>> nexts) {
    this->message = message;
    this->nexts = nexts;
}

std::string Question::getMessage() {
    return message;
}

std::pair<Conversation*,int> Question::respond(char interaction) {
    
    return std::make_pair(nullptr,0); //stub
}

std::vector<std::tuple<std::string, int, Conversation*>> Question::getNexts() const {
    return {}; //stub
}