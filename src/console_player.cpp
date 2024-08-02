#include "console_player.hpp"
#include "crop.hpp"
#include "item.hpp"
#include "villager.hpp"
#include "environment_tile.hpp"
#include "conversation.hpp"
#include "question.hpp"
#include <typeinfo>
#include <vector>
#include <tuple>
#include <print>
#include <cstring>
#include <string>
#include <iostream>

ConsolePlayer::ConsolePlayer()
{
    bool keepGoing = true;
    initializeWorld();
    while (keepGoing) {
        printf("current position: %d, %d\n", navigator.getPosition().first, navigator.getPosition().second);
        printf("facing: %c\n", navigator.getDirectionFacing());
        printf("what would you like to do?\n n -> walk north\n e -> walk east\n s -> walk south\n w -> walk west\n i  -> interact\n q -> quit\n");

        char action;
        scanf("%c", &action);
        switch (action) {
            case 'q':
            {
                keepGoing = false;
                break;
            } 
            case 'i':
            {
                WorldObject* facingObject = navigator.interact(inventory.getHeldItem());
                if (facingObject == nullptr)
                    break;
                if (typeid(*facingObject).name() == typeid(Villager).name()) {
                    talk((Villager*) facingObject);
                } else if (typeid(*facingObject).name() == typeid(Item).name()) {
                    if (inventory.hasSpace()) {
                        inventory.addItem(*((Item*) facingObject));
                        navigator.removeObjectFacing();
                    }
                }
                break;
            }
            case 'n':
            {
                navigator.walk('n');
                break;
            }
            case 'e':
            {
                navigator.walk('e');
                break;
            }
            case 's':
            {
                navigator.walk('s');
                break;
            }
            case 'w':
            {
                navigator.walk('w');
                break;
            }
            default:
            {
                printf("please enter a valid input.\n");
            }
            std::cin.ignore(100, '\n');
        }
    }
}

void ConsolePlayer::initializeWorld()
{

}

void ConsolePlayer::passDay()
{

}

void ConsolePlayer::talk(Villager* villager) {
    Conversation* conversation = villager->talk(inventory.getHeldItem()); // YourName == \t
    while (conversation != nullptr) {
        std::string message = conversation->getMessage();
        //the following two lines are adapted from https://stackoverflow.com/questions/9053687/trying-to-replace-words-in-a-string
        while (message.find("\t") != message.npos)
            message.replace(message.find("\t"), character.getName().length(), character.getName());
        printf("%s", message.c_str());

        char* action = nullptr;
        if (typeid(*conversation).name() == typeid(Question).name()) {
            Question question = *((Question*) conversation);
            std::vector<std::tuple<std::string, int, Conversation*>> nexts = question.getNexts();
            for (unsigned int i = 0; i < nexts.size(); i++) {
                using std::get;
                printf("'%u' : %s\n", i, get<0>(nexts[i]).c_str());
            }
            while (action == nullptr || -1 < *action - '0' < nexts.size()) {
                scanf("%c", action);
            }
        } else {
            printf("enter '0' to continue\n");
            while (action == nullptr || *action != '0')
                scanf("%c", action);
        }

        villager->changeFriendshipPointsBy(conversation->respond(*action).second);
        conversation = conversation->respond(*action).first;
    }
}