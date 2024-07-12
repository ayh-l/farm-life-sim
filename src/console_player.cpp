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

ConsolePlayer::ConsolePlayer()
{
    bool keepGoing = true;
    initializeWorld();
    while (keepGoing) {
        printf("current position: %d, %d\n", navigator.getPosition().first, navigator.getPosition().second);
        printf("facing: %d", navigator.getDirectionFacing());
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
                Villager* villager = navigator.interact(inventory.getHeldItem());
                if (villager != nullptr) {
                    talk(villager);
                }
                // interact();
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
                printf("please enter a valid input.");
            }
        }
    }
}

void ConsolePlayer::initializeWorld()
{

}

void ConsolePlayer::passDay()
{

}

//TODO edit because respond's signature changed (now includes friendship points to add)
void ConsolePlayer::talk(Villager* villager) {
    Conversation* conversation = villager->talk(inventory.getHeldItem(), character.getName());
    while (conversation != nullptr) {
        
        printf("%s", conversation->getMessage().c_str());
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
        conversation = conversation->respond(*action);
    }
}

// void ConsolePlayer::interact()
// {
//     EnvironmentTile* facingEnvTile = navigator.getEnvTileFacing();
//     if (facingEnvTile == nullptr) return; //aka at edge of map
//     Item* heldItem = inventory.getHeldItem();

//     WorldObject* facingObject = navigator.getObjectFacing();

//     std::string facingObjectType = typeid(facingObject).name();
//     if (facingObjectType == typeid(Crop).name()) {
//         std::string heldItemName = heldItem->getName();
//         if (heldItemName == "hoe") {
//             (*(Crop*) facingObject).kill();
//         }
//     } else if (facingObjectType == typeid(Item).name()) {
//         inventory.addItem(*(Item*) facingObject);
//         navigator.
//     } else if (facingObjectType == typeid(Villager).name()) {

//     }
// }