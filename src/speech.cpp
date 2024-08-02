#include "speech.hpp"
#include <string>

Speech::Speech(std::string message, Conversation* next) {
    this->message = message;
    this->next = next;
}

std::string Speech::getMessage() {
    return message;
}
std::pair<Conversation*,int> Speech::respond(char interaction) {
    return std::make_pair(next, 0);
}