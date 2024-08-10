/**
 * @file question.hpp
 * Definition of the Question class.
 */

#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>
#include <tuple>
#include "conversation.hpp"

class Question : public Conversation {
    public:

        /**
         * Constructs a Question with given message and vector of responses.
         * 
         * @param message this Question's message
         * @param nexts a non-empty vector of responses in form <[response string],[friendship point change],[next conversation]>.
         */
        Question(std::string message, std::vector<std::tuple<std::string, int, Conversation*>> nexts);

        /**
         * Returns this Question's message.
         * 
         * @return A string representing this Question's message (ie. what the speaking villager is saying)
         */
        std::string getMessage();

        /**
         * Responds to the Question and returns the next Conversation and friendship point pair.
         * 
         * @param interaction Char of digit representing user's choice of response, within range of [0, nexts.sizeOf()]
         * @return Pair containing pointer to next Conversation (nullptr if no following Conversation), and integer value of friendship points to be gained/lost due to response
         */
        std::pair<Conversation*,int> respond(char interaction);

        /**
         * Returns a vector containing tuples of possible responses.
         * 
         * @return vector of tuples of possible responses, in form <[response string],[friendship point change],[next conversation]>
         */
        std::vector<std::tuple<std::string, int, Conversation*>> getNexts() const;
        
    private:
        std::string message;
        std::vector<std::tuple<std::string, int, Conversation*>> nexts;
};

#endif