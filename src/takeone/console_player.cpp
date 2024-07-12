#include "console_player.h"
#include "villager.h"

ConsolePlayer::ConsolePlayer()
{
    bool keepGoing = true;
    initialize_world();
    while (keepGoing) {
        printf("current position: %d, %d\n", character.get_position().first, character.get_position().second);
        printf("facing: %d", character.get_direction_facing());
        printf("what would you like to do?\n 0 -> walk north\n 1 -> walk east\n 2 -> walk south\n 3 -> walk west\n 4  -> interact\n 5 -> quit\n");

        int action;
        scanf("%d", &action);
        if (action == 5) {
            printf("quitting.");
            keepGoing = false;
        } else if (action == 4) {
            printf("interacting...");
            interact();
        } else {
            printf("walking...");
            character.change_direction_facing(action);
            std::pair<int,int> new_position = maps[current_map].move(character.get_direction_facing(), character.get_position());
            if (new_position.first < 0) {
                current_map = new_position.second;
                new_position = maps[current_map].get_entrance_position(-1 * new_position.first);
            }
            character.change_position(new_position.first, new_position.second);
            printf("new position: %d, %d\n", character.get_position().first, character.get_position().second);
        }
    }
}

void ConsolePlayer::interact()
{
    std::pair<int,int> item_pos;
    switch (character.get_direction_facing()) {
        case 0: //north
        item_pos = character.get_up_position();
        break;
        case 1: //east
        item_pos = character.get_right_position();
        break;
        case 2: //south
        item_pos = character.get_down_position();
        break;
        case 3: //west
        item_pos = character.get_left_position();
        break;
    }
    ItemId* item_id = maps[current_map].get_item_id_at_pos(item_pos);
    Item item = item_directory[item_id->get_item_id().substr(0, 4)];
    ItemId item_held = character.get_item_held();

    switch (item_id->get_item_id()[0]) {
        case 'i':
            if (item.can_pickup()) {
                character.add_to_inventory(*item_id);
                printf("... %s added to inventory.", item.get_item_name());
                maps[current_map].remove_item_at_pos(item_pos);
            }
            if (item.get_item_msg().size() != 0) {
                printf("item msg: %s", item.get_item_msg());
            }
            if (item_id->get_item_id() == "i1" && &item_held != nullptr && item_held.get_item_id() == "t2") {
                item_id->soil_cultivate();
            }
        break;

        case 'c':
            if (&item_held == nullptr)
                break;
            if (item_held.get_item_id() == "t1") {
                item_id->crop_water();
                printf("... crop watered.");
            }
            if (item_held.get_item_id() == "t2") {
                maps[current_map].remove_item_at_pos(item_pos);
                printf("... crop destroyed.");
            }
        break;

        case 'v':
            Villager villager = *((Villager*) &item);
            if (&item_held != nullptr && item.can_gift()) {
                printf("...gifting item to %s.", villager.get_item_name());
                villager.gift(item_held);
                character.remove_item_held();
            } else {
                printf("...talking to %s.", villager.get_item_name());
                villager.talk();
            }
        break;
    }
}

void ConsolePlayer::initialize_world()
{

}

void ConsolePlayer::initialize_item_directory()
{

}

void ConsolePlayer::pass_day()
{
    
}