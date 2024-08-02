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
    int response = interaction - '0';
    return std::make_pair(std::get<2>(nexts[response]), std::get<1>(nexts[response]));
}

std::vector<std::tuple<std::string, int, Conversation*>> Question::getNexts() const {
    return nexts;
}