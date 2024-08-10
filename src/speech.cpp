/**
 * @file speech.cpp
 * Implementation of the Speech class.
 */

#include "speech.hpp"
#include <string>

/**
 * Constructs a Speech with given message and next Conversation (if any).
 * 
 * @param message this Speech's message
 * @param next pointer to next Conversation, if any
 */
Speech::Speech(std::string message, Conversation* next) {
    this->message = message;
    this->next = next;
}

/**
 * Returns this Speech's message.
 * 
 * @return A string representing this Speech's message (ie. what the speaking villager is saying)
 */
std::string Speech::getMessage() {
    return message;
}

/**
 * Responds to the Conversation and returns the next Conversation and friendship point pair.
 * 
 * @param interaction Char representing response. Any char is acceptable for Speeches, as there are no response choices
 * @return Pair containing pointer to next Conversation (nullptr if no following Conversation), and integer value of friendship points to be gained/lost due to response (always 0)
 */
std::pair<Conversation*,int> Speech::respond(char interaction) {
    return std::make_pair(next, 0);
}