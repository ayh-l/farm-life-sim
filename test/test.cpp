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
#include <vector>

TEST_CASE("Character") {
    Character character = Character();
    REQUIRE(character.getName() == "Luca");
    character.setName("Bob");
    REQUIRE(character.getName() == "Bob");
}

TEST_CASE("Crop") {
    Crop potato = Crop("Potato", false, 30);
    REQUIRE(potato.getName() == "Potato");
    REQUIRE(potato.isAlive());
    REQUIRE(!potato.isRipe());
    potato.kill();
    REQUIRE(!potato.isAlive());
    REQUIRE(!potato.isRipe());
    REQUIRE(potato.getFuturePrice() == 30);
}

TEST_CASE("EnvironmentTile") {
    EnvironmentTile water = EnvironmentTile("water", 2, 2, false, true);
    EnvironmentTile dirt = EnvironmentTile("dirt", 0, 0, true, false);
    REQUIRE(!water.walkable());
    REQUIRE(water.fishable());
    REQUIRE(water.watered() == 2);
    REQUIRE(water.tilled() == 2);
    REQUIRE(dirt.walkable());
    REQUIRE(!dirt.fishable());
    REQUIRE(dirt.watered() == 0);
    REQUIRE(dirt.tilled() == 0);

    water.till();
    dirt.till();
    REQUIRE(water.tilled() == 2);
    REQUIRE(dirt.tilled() == 1);

    water.till();
    dirt.till();
    REQUIRE(water.tilled() == 2);
    REQUIRE(dirt.tilled() == 1);

    water.water();
    dirt.water();
    REQUIRE(water.watered() == 2);
    REQUIRE(dirt.watered() == 1);

    water.water();
    dirt.water();
    REQUIRE(water.watered() == 2);
    REQUIRE(dirt.watered() == 1);
}

TEST_CASE("Inventory") {
    Inventory inventory = Inventory();
    REQUIRE(inventory.getFunds() == 0);
    REQUIRE(inventory.getHeldItem() == nullptr);
    REQUIRE(inventory.getItems().size() == 0);

    Item book = Item("book", 25, false);
    Item hoe = Item("hoe", 0, true);
    inventory.addItem(book);
    inventory.addItem(hoe);
    REQUIRE(inventory.getFunds() == 0);
    REQUIRE(inventory.getHeldItem() == nullptr);
    REQUIRE(inventory.getItems().size() == 2);
    
    inventory.sellHeldItem();
    REQUIRE(inventory.getFunds() == 0);
    REQUIRE(inventory.getHeldItem() == nullptr);
    REQUIRE(inventory.getItems().size() == 2);

    inventory.swapHeldItem();
    REQUIRE(inventory.getHeldItem() == &book);
    REQUIRE(inventory.getItems().size() == 2);
    inventory.swapHeldItem();
    REQUIRE(inventory.getHeldItem() == &hoe);
    REQUIRE(inventory.getItems().size() == 2);
    inventory.swapHeldItem();
    REQUIRE(inventory.getHeldItem() == nullptr); //when you circle around you start empty handed before going thru items again
    REQUIRE(inventory.getItems().size() == 2);

    inventory.swapHeldItem();
    inventory.sellHeldItem();
    REQUIRE(inventory.getHeldItem() == &hoe); //items shift back when sold
    REQUIRE(inventory.getItems().size() == 1);
    REQUIRE(inventory.getFunds() == 25);
    inventory.sellHeldItem();
    REQUIRE(inventory.getHeldItem() == &hoe); //items shift back when sold
    REQUIRE(inventory.getItems().size() == 1);
    REQUIRE(inventory.getFunds() == 25);

    inventory.setFunds(100);
    REQUIRE(inventory.getFunds() == 100);
}

TEST_CASE("Item") {
    Item priceTool = Item("Tool", 10, true);
    REQUIRE(priceTool.getName() == "Tool");
    REQUIRE(priceTool.isTool());
    REQUIRE(priceTool.getPrice() == 10);

    Crop tomatoCrop = Crop("Tomato", true, 10);
    Item tomatoItem = Item(tomatoCrop);
    REQUIRE(tomatoItem.getName() == "Tomato");
    REQUIRE(tomatoItem.getPrice() == 10);
    REQUIRE(!tomatoItem.isTool());
}

TEST_CASE("Navigator") {
    //TODO
}

TEST_CASE("Question") {
    std::vector<std::tuple<std::string, int, Conversation*>> nextsToast;
    nextsToast[0] = std::make_tuple("B: Sweet.", 5, nullptr);
    nextsToast[1] = std::make_tuple("B: Savoury.", 0, nullptr);
    std::vector<std::tuple<std::string, int, Conversation*>> nexts;
    nexts[0] = std::make_tuple("B: Chocolate!", 10, &Speech("A: No way, me too!", nullptr));
    nexts[1] = std::make_tuple("B: French toast!", 0, &Question("A: Do you like french toast sweet or savoury?", nextsToast));
    nexts[2] = std::make_tuple("B: It's a secret!", -10, nullptr);
    Question foodQuestion = Question("A: What's your favourite food?", nexts);

    REQUIRE(foodQuestion.getMessage() == "A: What's your favourite food?");
    REQUIRE(foodQuestion.getNexts() == nexts);
    
    std::pair<Conversation*,int> chocolateResponse = foodQuestion.respond('0');
    std::pair<Conversation*,int> toastResponse = foodQuestion.respond('0');
    std::pair<Conversation*,int> secretResponse = foodQuestion.respond('0');

    REQUIRE(chocolateResponse.first->getMessage() == "A: No way, me too!");
    REQUIRE(chocolateResponse.first->respond('0').first == nullptr);
    REQUIRE(chocolateResponse.second == 10);

    REQUIRE(toastResponse.first->getMessage() == "A: Do you like french toast sweet or savoury?");
    REQUIRE(((Question*) toastResponse.first)->getNexts() == nextsToast);
    REQUIRE(toastResponse.first->respond('0').second == 5);
    REQUIRE(toastResponse.first->respond('1').second == 0);

    REQUIRE(secretResponse.first == nullptr);
    REQUIRE(secretResponse.second == -10);
}