/**
 * @file question.cpp
 * Implementation of the Question class.
 */

#include "question.hpp"
#include <utility>

/**
 * Constructs a Question with given message and vector of responses.
 * 
 * @param message this Question's message
 * @param nexts a non-empty vector of responses in form <[response string],[friendship point change],[next conversation]>
 */
Question::Question(std::string message, std::vector<std::tuple<std::string, int, Conversation*>> nexts) {
    this->message = message;
    this->nexts = nexts;
}

/**
 * Returns this Question's message.
 * 
 * @return A string representing this Question's message (ie. what the speaking villager is saying)
 */
std::string Question::getMessage() {
    return message;
}

/**
 * Responds to the Question and returns the next Conversation and friendship point pair.
 * 
 * @param interaction Char of digit representing user's choice of response, within range of [0, nexts.sizeOf()]
 * @return Pair containing pointer to next Conversation (nullptr if no following Conversation), and integer value of friendship points to be gained/lost due to response
 */
std::pair<Conversation*,int> Question::respond(char interaction) {
    int response = interaction - '0';
    return std::make_pair(std::get<2>(nexts[response]), std::get<1>(nexts[response]));
}

/**
 * Returns a vector containing tuples of possible responses.
 * 
 * @return vector of tuples of possible responses, in form <[response string],[friendship point change],[next conversation]>
 */
std::vector<std::tuple<std::string, int, Conversation*>> Question::getNexts() const {
    return nexts;
}