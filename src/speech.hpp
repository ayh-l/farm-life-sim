/**
 * @file speech.hpp
 * Definition of the Speech class.
 */

#ifndef SPEECH_H
#define SPEECH_H

#include <string>
#include "conversation.hpp"

class Speech : public Conversation {

    public:

        /**
         * Constructs a Speech with given message and next Conversation (if any).
         * 
         * @param message this Speech's message
         * @param next pointer to next Conversation, if any
         */
        Speech(std::string message, Conversation* next);

        /**
         * Returns this Speech's message.
         * 
         * @return A string representing this Speech's message (ie. what the speaking villager is saying)
         */
        std::string getMessage();

        /**
         * Responds to the Conversation and returns the next Conversation and friendship point pair.
         * 
         * @param interaction Char representing response. Any char is acceptable for Speeches, as there are no response choices
         * @return Pair containing pointer to next Conversation (nullptr if no following Conversation), and integer value of friendship
         *         points to be gained/lost due to response (always 0)
         */
        std::pair<Conversation*,int> respond(char interaction);

    private:
    
        std::string message;
        Conversation* next;
};

#endif