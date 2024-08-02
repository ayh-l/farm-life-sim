#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>
#include <tuple>
#include "conversation.hpp"

//TODO comment class/mtd desc, add fields, privates...

class Question : public Conversation {
    public:
        Question(std::string message, std::vector<std::tuple<std::string, int, Conversation*>> nexts); //nexts must not be empty
        std::string getMessage();
        std::pair<Conversation*,int> respond(char interaction); //assumes interaction is within response range (a number char)
        std::vector<std::tuple<std::string, int, Conversation*>> getNexts() const;
    private:
        std::string message;
        std::vector<std::tuple<std::string, int, Conversation*>> nexts;
};

#endif