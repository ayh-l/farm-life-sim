#ifndef SPEECH_H
#define SPEECH_H

#include <string>
#include "conversation.hpp"

//TODO comment class/mtd desc, add fields, privates...

class Speech : public Conversation {
    public:
        Speech(std::string message, Conversation* next);
        std::string getMessage();
        std::pair<Conversation*,int> respond(char interaction); //int is always 0
    private:
        std::string message;
        Conversation* next;
};

#endif