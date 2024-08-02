#include "speech.hpp"
#include <string>

Speech::Speech(std::string message, Conversation* next) {

}

std::string Speech::getMessage() {
    return ""; //TODO stub
}
std::pair<Conversation*,int> Speech::respond(char interaction) {
    return std::make_pair(nullptr,0); //stub
}