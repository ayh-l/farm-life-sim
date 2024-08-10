/**
 * @file conversation.hpp
 * Definition of the Conversation class.
 */

#ifndef CONVO_H
#define CONVO_H

#include <string>

class Conversation {
        public:

                /**
                 * Responds to the Conversation and returns the next Conversation and friendship point pair.
                 * 
                 * @param interaction Char representing user's choice of response
                 * @return Pair containing pointer to next Conversation (nullptr if no following Conversation), and integer value of friendship points to be gained/lost due to response
                 */
                virtual std::pair<Conversation*,int> respond(char interaction) = 0;

                /**
                 * Returns this Conversation's message.
                 * 
                 * @return A string representing this Conversation's message (ie. what the speaking villager is saying)
                 */
                virtual std::string getMessage() = 0;
};

#endif