#ifndef CONVO_H
#define CONVO_H

#include <string>

//TODO comment class/mtd desc, add fields, privates...

class Conversation {
        public:
                virtual std::pair<Conversation*,int> respond(char interaction) = 0; //returns pointer to next convo and friendship points earned/lost with this response
                virtual std::string getMessage() = 0;
};

#endif