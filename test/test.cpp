#include "../include/Catch2/catch_amalgamated.hpp"
#include "../src/character.hpp"
#include "../src/conversation.hpp"
#include "../src/crop.hpp"
#include "../src/environment_tile.hpp"
#include "../src/inventory.hpp"
#include "../src/item.hpp"
#include "../src/navigator.hpp"
#include "../src/question.hpp"
#include "../src/speech.hpp"
#include "../src/villager.hpp"
#include "../src/worldobject.hpp"
#include <list>
#include <tuple>
#include <algorithm>

TEST_CASE("Character") {
    Character character = Character();
    REQUIRE(character.getName() == "Luca");
    character.setName("Bob");
    REQUIRE(character.getName() == "Bob");
}

TEST_CASE("Crop") {
    Crop potato = Crop("Potato", 30);
    REQUIRE(potato.getName() == "Potato");
    REQUIRE(potato.isAlive());
    potato.kill();
    REQUIRE(!potato.isAlive());
    REQUIRE(potato.getFuturePrice() == 30);
}

TEST_CASE("EnvironmentTile") {
    EnvironmentTile water = EnvironmentTile("water", 2, 2, false, true);
    EnvironmentTile dirt = EnvironmentTile("dirt", 0, 0, true, false);
    REQUIRE(!water.isWalkable());
    REQUIRE(water.isFishable());
    REQUIRE(!water.isWatered());
    REQUIRE(!water.isTilled());
    REQUIRE(dirt.isWalkable());
    REQUIRE(!dirt.isFishable());
    REQUIRE(!dirt.isWatered());
    REQUIRE(!dirt.isTilled());

    water.till();
    dirt.till();
    REQUIRE(!water.isTilled());
    REQUIRE(dirt.isTilled());

    water.till();
    dirt.till();
    REQUIRE(!water.isTilled());
    REQUIRE(dirt.isTilled());

    water.water();
    dirt.water();
    REQUIRE(!water.isWatered());
    REQUIRE(dirt.isWatered());

    water.water();
    dirt.water();
    REQUIRE(!water.isWatered());
    REQUIRE(dirt.isWatered());
}

TEST_CASE("Inventory basic") {
    Inventory inventory = Inventory();
    REQUIRE(inventory.getFunds() == 0);
    REQUIRE(inventory.getHeldItem() == nullptr);
    REQUIRE(inventory.getItems().size() == 0);

    Item book = Item("book", 25, false);
    Item hoe = Item("hoe", 2, true);
    inventory.addItem(hoe);
    inventory.addItem(book);
    REQUIRE(inventory.getFunds() == 0);
    REQUIRE(inventory.getHeldItem() == nullptr);
    REQUIRE(inventory.getItems().size() == 2);
    
    inventory.sellHeldItem();
    REQUIRE(inventory.getFunds() == 0);
    REQUIRE(inventory.getHeldItem() == nullptr);
    REQUIRE(inventory.getItems().size() == 2);

    inventory.swapHeldItem();
    REQUIRE(inventory.getHeldItem()->getName() == "hoe");
    REQUIRE(inventory.getItems().size() == 2);
    inventory.swapHeldItem();
    REQUIRE(inventory.getHeldItem()->getName() == "book");
    REQUIRE(inventory.getItems().size() == 2);
    inventory.swapHeldItem();
    for (int i = 2; i < 7; i++) {
        inventory.swapHeldItem();
        REQUIRE(inventory.getHeldItem() == nullptr);
    }

    inventory.swapHeldItem();
    REQUIRE(inventory.getHeldItem() == nullptr);
    inventory.swapHeldItem();
    REQUIRE(inventory.getHeldItem()->getName() == "hoe");
    inventory.sellHeldItem();
    REQUIRE(inventory.getHeldItem()->getName() == "hoe");
    REQUIRE(inventory.getItems().size() == 2);
    REQUIRE(inventory.getFunds() == 0);
    inventory.swapHeldItem();
    REQUIRE(inventory.getHeldItem()->getName() == "book");
    inventory.sellHeldItem();
    REQUIRE(inventory.getHeldItem() == nullptr);
    REQUIRE(inventory.getItems().size() == 1);
    REQUIRE(inventory.getFunds() == 25);

    inventory.setFunds(100);
    REQUIRE(inventory.getFunds() == 100);
    inventory.changeFundsBy(110);
    REQUIRE(inventory.getFunds() == 210);
    inventory.changeFundsBy(-30);
    REQUIRE(inventory.getFunds() == 180);
}

TEST_CASE("Inventory half testing") {
    Inventory inventory = Inventory();
    inventory.addItem(Item("hoe", 0, true));
    inventory.addItem(Item("watering can", 0, true));
    inventory.addItem(Item("fishing rod", 0, true));
    inventory.addItem(Item("i3", 0, false));
    inventory.addItem(Item("i4", 0, false));
    inventory.addItem(Item("i5", 0, false));
    inventory.addItem(Item("i6", 0, false));
    inventory.addItem(Item("i7", 0, false));
    inventory.addItem(Item("i8", 0, false));
    inventory.addItem(Item("i9", 0, false));
    inventory.addItem(Item("i10", 0, false));
    inventory.addItem(Item("i11", 0, false));
    inventory.addItem(Item("i12", 0, false));
    inventory.addItem(Item("i13", 0, false));
    inventory.addItem(Item("i14", 0, false));
    REQUIRE(inventory.hasSpace());
    inventory.addItem(Item("i15", 0, false));
    REQUIRE(!inventory.hasSpace());
    REQUIRE(inventory.getItems().size() == 16);
    
    inventory.swapInventoryHalf();
    REQUIRE(inventory.getHeldItem() == nullptr);
    inventory.swapHeldItem();
    REQUIRE(inventory.getHeldItem()->getName() == "i8");
    inventory.swapHeldItem();
    REQUIRE(inventory.getHeldItem()->getName() == "i9");

    inventory.swapInventoryHalf();
    REQUIRE(inventory.getHeldItem()->getName() == "watering can");
}

TEST_CASE("Item") {
    Item priceTool = Item("Tool", 10, true);
    REQUIRE(priceTool.getName() == "Tool");
    REQUIRE(priceTool.isTool());
    REQUIRE(priceTool.getPrice() == 10);

    Crop tomatoCrop = Crop("Tomato", 10);
    Item tomatoItem = Item(tomatoCrop);
    REQUIRE(tomatoItem.getName() == "Tomato");
    REQUIRE(tomatoItem.getPrice() == 10);
    REQUIRE(!tomatoItem.isTool());
}

TEST_CASE("Navigator") {
    Navigator navigator = Navigator();
    REQUIRE(navigator.getCurrentMapIndex() == 0);
    REQUIRE(navigator.getPosition() == std::make_pair(2,3));
    REQUIRE(navigator.getDirectionFacing() == 's');
    
    SECTION("walking unobstructed") {
        navigator.walk('e');
        REQUIRE(navigator.getCurrentMapIndex() == 0);
        REQUIRE(navigator.getPosition() == std::make_pair(1,0));
        REQUIRE(navigator.getDirectionFacing() == 'e');
        navigator.walk('e');
        navigator.walk('e');
        navigator.walk('e');
        navigator.walk('s');
        REQUIRE(navigator.getCurrentMapIndex() == 0);
        REQUIRE(navigator.getPosition() == std::make_pair(4,1));
        REQUIRE(navigator.getDirectionFacing() == 's');
        navigator.walk('w');
        REQUIRE(navigator.getCurrentMapIndex() == 0);
        REQUIRE(navigator.getPosition() == std::make_pair(3,1));
        REQUIRE(navigator.getDirectionFacing() == 'w');
        navigator.walk('n');
        REQUIRE(navigator.getCurrentMapIndex() == 0);
        REQUIRE(navigator.getPosition() == std::make_pair(3,0));
        REQUIRE(navigator.getDirectionFacing() == 'n');
    }

    SECTION("walking into edge of map and unwalkable environment tiles") {
        navigator.walk('e');
        navigator.walk('n');
        REQUIRE(navigator.getCurrentMapIndex() == 0);
        REQUIRE(navigator.getPosition() == std::make_pair(1,0));
        REQUIRE(navigator.getDirectionFacing() == 'n');
        navigator.walk('s');
        REQUIRE(navigator.getCurrentMapIndex() == 0);
        REQUIRE(navigator.getPosition() == std::make_pair(1,0));
        REQUIRE(navigator.getDirectionFacing() == 's');
        navigator.setPosition(1, 3);
        navigator.walk('n');
        REQUIRE(navigator.getCurrentMapIndex() == 0);
        REQUIRE(navigator.getPosition() == std::make_pair(1, 3));
        REQUIRE(navigator.getDirectionFacing() == 'n');
        navigator.walk('s');
        navigator.walk('s');
        REQUIRE(navigator.getCurrentMapIndex() == 0);
        REQUIRE(navigator.getPosition() == std::make_pair(1, 4));
        REQUIRE(navigator.getDirectionFacing() == 's');
        navigator.setPosition(0, 2);
        navigator.walk('e');
        REQUIRE(navigator.getCurrentMapIndex() == 0);
        REQUIRE(navigator.getPosition() == std::make_pair(0, 2));
        REQUIRE(navigator.getDirectionFacing() == 'e');
        navigator.walk('w');
        REQUIRE(navigator.getCurrentMapIndex() == 0);
        REQUIRE(navigator.getPosition() == std::make_pair(0, 2));
        REQUIRE(navigator.getDirectionFacing() == 'w');
        navigator.setPosition(3, 2);
        navigator.walk('w');
        REQUIRE(navigator.getCurrentMapIndex() == 0);
        REQUIRE(navigator.getPosition() == std::make_pair(3, 2));
        REQUIRE(navigator.getDirectionFacing() == 'w');
        navigator.setPosition(7, 1);
        navigator.walk('e');
        REQUIRE(navigator.getCurrentMapIndex() == 0);
        REQUIRE(navigator.getPosition() == std::make_pair(7, 1));
        REQUIRE(navigator.getDirectionFacing() == 'e');
    }

    SECTION("travelling on path") {
        Navigator navigator = Navigator();
        navigator.setPosition(6, 2);
        navigator.walk('e');
        REQUIRE(navigator.getCurrentMapIndex() == 0);
        REQUIRE(navigator.getPosition() == std::make_pair(7, 2));
        navigator.walk('e');
        REQUIRE(navigator.getCurrentMapIndex() == 1);
        REQUIRE(navigator.getPosition() == std::make_pair(0, 2));
        REQUIRE(navigator.getDirectionFacing() == 'e');
    }

    SECTION("passDay: test villager friendship, crop growth/ripening, item respawn") {
        Villager* jo = static_cast<Villager*>(navigator.getMaps()[4].getWorldObjectAtPosition(0,2));
        Villager* laurie = static_cast<Villager*>(navigator.getMaps()[5].getWorldObjectAtPosition(2,1));
        jo->talk(nullptr);
        navigator.getMaps()[0].addWorldObjectAtPosition(4,1, Crop("regular vegetable", 10));
        navigator.getMaps()[0].addWorldObjectAtPosition(4,2, Crop("ripening vegetable", 20));
        navigator.getMaps()[0].addWorldObjectAtPosition(4,3, Crop("vegetable to be neglected", 30));
        Crop* regCrop = static_cast<Crop*>(navigator.getMaps()[0].getWorldObjectAtPosition(4,1));
        Crop* ripCrop = static_cast<Crop*>(navigator.getMaps()[0].getWorldObjectAtPosition(4,2));
        Crop* negCrop = static_cast<Crop*>(navigator.getMaps()[0].getWorldObjectAtPosition(4,3));
        ripCrop->setDaysTillRipe(1);
        navigator.getMaps()[0].getEnvironmentTileAtPosition(4,1)->water();
        navigator.getMaps()[0].getEnvironmentTileAtPosition(4,2)->water();
        REQUIRE(navigator.getMaps()[2].getWorldObjectAtPosition(5,1)->getName() == "apple");
        REQUIRE(navigator.getMaps()[2].getWorldObjectAtPosition(6,2)->getName() == "apple");
        navigator.getMaps()[2].removeWorldObjectAtPosition(5,1);
        REQUIRE(navigator.getMaps()[2].getWorldObjectAtPosition(5,1) == nullptr);
        navigator.passDayUpdateMaps();

        REQUIRE(jo->getFriendshipPoints() == 5);
        REQUIRE(laurie->getFriendshipPoints() == 0);
        REQUIRE(!jo->didTalkToToday());
        REQUIRE(!laurie->didTalkToToday());
        Item* harvest = static_cast<Item*>(navigator.getMaps()[0].getWorldObjectAtPosition(4,1));
        REQUIRE(!harvest->isTool());
        REQUIRE(regCrop->isAlive());
        REQUIRE(regCrop->getDaysTillRipe() == 9);
        REQUIRE(negCrop->getDaysTillRipe() == -1);
        REQUIRE(!negCrop->isAlive());
        REQUIRE(navigator.getMaps()[2].getWorldObjectAtPosition(5,1)->getName() == "apple");
        REQUIRE(navigator.getMaps()[2].getWorldObjectAtPosition(6,2)->getName() == "apple");
    }

    SECTION("modifying facing object") {
//todo
    }

    SECTION("interact") {
//todo
    }
}

TEST_CASE("Question and Speech") {
    std::vector<std::tuple<std::string, int, Conversation*>> nextsToast;
    nextsToast.push_back(std::make_tuple("B: Sweet.", 5, nullptr));
    nextsToast.push_back(std::make_tuple("B: Savoury.", 0, nullptr));
    std::vector<std::tuple<std::string, int, Conversation*>> nexts;
    Speech chocolateTwo = Speech("Chocolate is my reason for living.", nullptr);
    Speech chocolateOne = Speech("A: No way, me too!", &chocolateTwo);
    nexts.push_back(std::make_tuple("B: Chocolate!", 10, &chocolateOne));
    Question toast = Question("A: Do you like french toast sweet or savoury?", nextsToast);
    nexts.push_back(std::make_tuple("B: French toast!", 0, &toast));
    nexts.push_back(std::make_tuple("B: It's a secret!", -10, nullptr));
    Question foodQuestion = Question("A: What's your favourite food?", nexts);

    REQUIRE(foodQuestion.getMessage() == "A: What's your favourite food?");
    REQUIRE(foodQuestion.getNexts() == nexts);
    
    std::pair<Conversation*,int> chocolateResponse = foodQuestion.respond('0');
    std::pair<Conversation*,int> toastResponse = foodQuestion.respond('1');
    std::pair<Conversation*,int> secretResponse = foodQuestion.respond('2');

    REQUIRE(chocolateResponse.first->getMessage() == "A: No way, me too!");
    REQUIRE(chocolateResponse.first->respond('0').first->getMessage() == "Chocolate is my reason for living.");
    REQUIRE(chocolateResponse.first->respond('0').second == 0);
    REQUIRE(chocolateResponse.second == 10);

    REQUIRE(toastResponse.first->getMessage() == "A: Do you like french toast sweet or savoury?");
    REQUIRE(((Question*) toastResponse.first)->getNexts() == nextsToast);
    REQUIRE(toastResponse.first->respond('0').second == 5);
    REQUIRE(toastResponse.first->respond('1').second == 0);

    REQUIRE(secretResponse.first == nullptr);
    REQUIRE(secretResponse.second == -10);
}

void correctConversationForHeartLevelTest(int friendshipPoints, Villager* villager) {
    bool conversationsVaried = false;
    std::vector<Conversation*>* acceptableConversations;

    if (0 <= friendshipPoints && friendshipPoints < 25)
        acceptableConversations = villager->getZeroHeartConversations();
    if (25 <= friendshipPoints && friendshipPoints < 50)
        acceptableConversations = villager->getOneHeartConversations();
    if (50 <= friendshipPoints && friendshipPoints < 75)
        acceptableConversations = villager->getTwoHeartConversations();
    if (75 <= friendshipPoints && friendshipPoints <= 100)
        acceptableConversations = villager->getThreeHeartConversations();

    for (int i = 0; i < 10; i++) {
        Conversation* convoOne = villager->talk(nullptr);
        Conversation* convoTwo = villager->talk(nullptr);
        //the two following lines are adapted from https://stackoverflow.com/questions/3450860/check-if-a-stdvector-contains-a-certain-object
        REQUIRE(std::find(acceptableConversations->begin(), acceptableConversations->end(), convoOne) != acceptableConversations->end());
        REQUIRE(std::find(acceptableConversations->begin(), acceptableConversations->end(), convoTwo) != acceptableConversations->end());
        if (convoOne != convoTwo)
            conversationsVaried = true;
    }
    REQUIRE(conversationsVaried);
}

TEST_CASE("Villager") {
    Speech zeroConvoOne = Speech("Zero convo one.", nullptr);
    Speech zeroConvoTwo = Speech("Zero convo two.", nullptr);
    Speech zeroConvoThree = Speech("Zero convo three.", nullptr);
    Speech oneConvoOne = Speech("One convo one.", nullptr);
    Speech oneConvoTwo = Speech("One convo two.", nullptr);
    Speech oneConvoThree = Speech("One convo three.", nullptr);
    Speech twoConvoOne = Speech("Zero convo one.", nullptr);
    Speech twoConvoTwo = Speech("Zero convo two.", nullptr);
    Speech twoConvoThree = Speech("Zero convo three.", nullptr);
    Speech threeConvoOne = Speech("One convo one.", nullptr);
    Speech threeConvoTwo = Speech("One convo two.", nullptr);
    Speech threeConvoThree = Speech("One convo three.", nullptr);
    std::vector<Conversation*> zeroHeartConvos = {&zeroConvoOne,
                                                  &zeroConvoTwo,
                                                  &zeroConvoThree};
    std::vector<Conversation*> oneHeartConvos = {&oneConvoOne,
                                                 &oneConvoTwo,
                                                 &oneConvoThree};
    std::vector<Conversation*> twoHeartConvos = {&twoConvoOne,
                                                  &twoConvoTwo,
                                                  &twoConvoThree};
    std::vector<Conversation*> threeHeartConvos = {&threeConvoOne,
                                                 &threeConvoTwo,
                                                 &threeConvoThree};
    Speech defaultReply = Speech("Thanks!", nullptr);
    Speech appleReply = Speech("I love apples!", nullptr);
    std::unordered_map<std::string,std::pair<int,Conversation*>> giftConversations = {{"default", std::make_pair(0, &defaultReply)},
                                                                                      {"apple", std::make_pair(0, &appleReply)}};
    Villager june = Villager("June", 0, &zeroHeartConvos, &oneHeartConvos, &twoHeartConvos, &threeHeartConvos, &giftConversations);

    REQUIRE(june.getName() == "June");
    REQUIRE(june.getFriendshipPoints() == 0);
    june.changeFriendshipPointsBy(10);
    REQUIRE(june.getFriendshipPoints() == 10);
    june.changeFriendshipPointsBy(-20);
    REQUIRE(june.getFriendshipPoints() == 0);

    REQUIRE(!june.didTalkToToday());
    correctConversationForHeartLevelTest(0, &june);
    REQUIRE(june.didTalkToToday());
    june.setFriendshipPoints(24);
    REQUIRE(june.getFriendshipPoints() == 24);
    correctConversationForHeartLevelTest(24, &june);
    june.setFriendshipPoints(25);
    correctConversationForHeartLevelTest(25, &june);
    june.setFriendshipPoints(49);
    correctConversationForHeartLevelTest(49, &june);
    june.setFriendshipPoints(50);
    correctConversationForHeartLevelTest(50, &june);
    june.setFriendshipPoints(74);
    correctConversationForHeartLevelTest(74, &june);
    june.setFriendshipPoints(75);
    correctConversationForHeartLevelTest(75, &june);
    june.setFriendshipPoints(100);
    correctConversationForHeartLevelTest(100, &june);

    Item apple = Item("apple", 0, false);
    Item notApple = Item("not an apple", 0, false);
    REQUIRE(june.talk(&apple)->getMessage() == "I love apples!");
    REQUIRE(june.talk(&notApple)->getMessage() == "Thanks!");
}

TEST_CASE("World Object") {
    WorldObject object = WorldObject();
    object.setName("obj");
    REQUIRE(object.getName() == "obj");
}