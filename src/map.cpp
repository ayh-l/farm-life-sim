#include "map.hpp"

Map::Map(int mapId) {
    switch (mapId) {
        case 0: //farm
            width = 8;
            height = 5;
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    addEnvironmentTileAtPosition(x, y, EnvironmentTile("grass", 0, 0, true, false));
                }
            }
            addEnvironmentTileAtPosition(1, 1, EnvironmentTile("home left roof",       2, 2, false, false));
            addEnvironmentTileAtPosition(2, 1, EnvironmentTile("home right roof",      2, 2, false, false));
            addEnvironmentTileAtPosition(1, 2, EnvironmentTile("home window",          2, 2, false, false));
            addEnvironmentTileAtPosition(2, 2, EnvironmentTile("home door",            2, 2, false, false));
            addEnvironmentTileAtPosition(7, 2, EnvironmentTile("horizontal wood path", 2, 2, true,  false, {'e',  1, 0, 2}));
            addEnvironmentTileAtPosition(1, 3, EnvironmentTile("hardwood floor",       2, 2, true,  false));
            addEnvironmentTileAtPosition(2, 3, EnvironmentTile("hardwood floor",       2, 2, true,  false, {'n',  3, 1, 2}));
            addEnvironmentTileAtPosition(7, 3, EnvironmentTile("pond water",           2, 2, false, true));
            break;

        case 1: //town
            width = 8;
            height = 5;
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    addEnvironmentTileAtPosition(x, y, EnvironmentTile("grass", 2, 2, true, false));
                }
            }
            addEnvironmentTileAtPosition(1, 1, EnvironmentTile("west truck front",     2, 2, false, false));
            addEnvironmentTileAtPosition(2, 1, EnvironmentTile("west truck back",      2, 2, false, false));
            addEnvironmentTileAtPosition(4, 1, EnvironmentTile("duplex west roof",     2, 2, false, false));
            addEnvironmentTileAtPosition(5, 1, EnvironmentTile("duplex centre roof",   2, 2, false, false));
            addEnvironmentTileAtPosition(6, 1, EnvironmentTile("duplex east roof",     2, 2, false, false));
            addEnvironmentTileAtPosition(0, 2, EnvironmentTile("horizontal wood path", 2, 2, true, false, {'w', 0, 7, 2}));
            addEnvironmentTileAtPosition(1, 2, EnvironmentTile("vendor table",         2, 2, false, false));
            addWorldObjectAtPosition(2, 2, Villager("Meg"));
            addEnvironmentTileAtPosition(4, 2, EnvironmentTile("duplex west door",     2, 2, false, false, {'n', 4, 1, 2}));
            addEnvironmentTileAtPosition(5, 2, EnvironmentTile("duplex centre front",  2, 2, false, false));
            addEnvironmentTileAtPosition(6, 2, EnvironmentTile("duplex east door",     2, 2, false, false, {'n', 5, 1, 2}));
            addEnvironmentTileAtPosition(0, 4, EnvironmentTile("tree",                 2, 2, false, false));
            addEnvironmentTileAtPosition(1, 4, EnvironmentTile("vertical dirt path",   2, 2, false, false, {'s', 2, 1, 0}));
            addEnvironmentTileAtPosition(2, 4, EnvironmentTile("tree",                 2, 2, false, false));

            break;

        case 2: //forest
            width = 8;
            height = 5;
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    addEnvironmentTileAtPosition(x, y, EnvironmentTile("grass", 2, 2, true, false));
                }
            }
            addEnvironmentTileAtPosition(0, 0, EnvironmentTile("tree",                 2, 2, false, false));
            addEnvironmentTileAtPosition(1, 0, EnvironmentTile("vertical dirt path",   2, 2, false, false, {'n', 1, 1, 4}));
            addEnvironmentTileAtPosition(2, 0, EnvironmentTile("tree",                 2, 2, false, false));
            addEnvironmentTileAtPosition(3, 0, EnvironmentTile("tree",                 2, 2, false, false));
            addEnvironmentTileAtPosition(4, 0, EnvironmentTile("tree",                 2, 2, false, false));
            addEnvironmentTileAtPosition(5, 0, EnvironmentTile("tree",                 2, 2, false, false));
            addEnvironmentTileAtPosition(6, 0, EnvironmentTile("tree",                 2, 2, false, false));
            addEnvironmentTileAtPosition(7, 0, EnvironmentTile("tree",                 2, 2, false, false));
            addEnvironmentTileAtPosition(0, 1, EnvironmentTile("tree",                 2, 2, false, false));
            addEnvironmentTileAtPosition(7, 1, EnvironmentTile("tree",                 2, 2, false, false));
            addEnvironmentTileAtPosition(0, 2, EnvironmentTile("tree",                 2, 2, false, false));
            addEnvironmentTileAtPosition(2, 2, EnvironmentTile("tree house west roof", 2, 2, false, false));
            addEnvironmentTileAtPosition(3, 2, EnvironmentTile("tree house east roof", 2, 2, false, false));
            addEnvironmentTileAtPosition(5, 2, EnvironmentTile("apple tree",           2, 2, false, false));
            addEnvironmentTileAtPosition(7, 2, EnvironmentTile("tree",                 2, 2, false, false));
            addEnvironmentTileAtPosition(0, 3, EnvironmentTile("tree",                 2, 2, false, false));
            addEnvironmentTileAtPosition(2, 3, EnvironmentTile("tree house door",      2, 2, false, false, {'e', 6, 1, 2}));
            addEnvironmentTileAtPosition(3, 3, EnvironmentTile("tree house window",    2, 2, false, false));
            addEnvironmentTileAtPosition(7, 3, EnvironmentTile("tree",                 2, 2, false, false));
            addEnvironmentTileAtPosition(0, 4, EnvironmentTile("tree",                 2, 2, false, false));
            addEnvironmentTileAtPosition(1, 4, EnvironmentTile("tree",                 2, 2, false, false));
            addEnvironmentTileAtPosition(2, 4, EnvironmentTile("tree",                 2, 2, false, false));
            addEnvironmentTileAtPosition(3, 4, EnvironmentTile("tree",                 2, 2, false, false));
            addEnvironmentTileAtPosition(4, 4, EnvironmentTile("tree",                 2, 2, false, false));
            addEnvironmentTileAtPosition(5, 4, EnvironmentTile("tree",                 2, 2, false, false));
            addEnvironmentTileAtPosition(6, 4, EnvironmentTile("tree",                 2, 2, false, false));
            addEnvironmentTileAtPosition(7, 4, EnvironmentTile("tree",                 2, 2, false, false));

            break;

        case 3: //home
            width = 3;
            height = 3;
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    addEnvironmentTileAtPosition(x, y, EnvironmentTile("hardwood floor", 2, 2, true, false));
                }
            }
            addEnvironmentTileAtPosition(2, 0, EnvironmentTile("bed",         2, 2, false, false));
            addEnvironmentTileAtPosition(1, 2, EnvironmentTile("welcome mat 0", 2, 2, true,  false, {'s', 0, 2, 3}));
            break;

        case 4: //house1
            width = 3;
            height = 3;
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    addEnvironmentTileAtPosition(x, y, EnvironmentTile("hardwood floor", 2, 2, true, false));
                }
            }
            addEnvironmentTileAtPosition(0, 0, EnvironmentTile("bookshelf", 2, 2, false, false));
            addEnvironmentTileAtPosition(2, 0, EnvironmentTile("bed", 2, 2, false,  false));
            addEnvironmentTileAtPosition(1, 1, EnvironmentTile("square rug", 2, 2, true, false));
            addWorldObjectAtPosition(0, 2, Villager("Jo"));
            addEnvironmentTileAtPosition(1, 2, EnvironmentTile("welcome mat 1", 2, 2, true,  false, {'s',  1, 4, 3}));
            break;

        case 5: //house2
            width = 3;
            height = 3;
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    addEnvironmentTileAtPosition(x, y, EnvironmentTile("hardwood floor", 2, 2, true, false));
                }
            }
            addEnvironmentTileAtPosition(0, 0, EnvironmentTile("bed",    2, 2, false, false));
            addEnvironmentTileAtPosition(2, 0, EnvironmentTile("guitar", 2, 2, false, false));
            addEnvironmentTileAtPosition(0, 1, EnvironmentTile("desk",   2, 2, false, false));
            addWorldObjectAtPosition(2, 1, Villager("Laurie"));
            addEnvironmentTileAtPosition(1, 2, EnvironmentTile("welcome mat 2", 2, 2, true,  false, {'s',  1, 6, 3}));
            break;

        case 6: //stumphouse
            width = 3;
            height = 3;
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    addEnvironmentTileAtPosition(x, y, EnvironmentTile("tree floor", 2, 2, true, false));
                }
            }
            addEnvironmentTileAtPosition(0, 0, EnvironmentTile("tree pond", 2, 2, false, true));
            addEnvironmentTileAtPosition(2, 0, EnvironmentTile("hammock", 2, 2, false, false));
            addEnvironmentTileAtPosition(0, 1, EnvironmentTile("tree pond", 2, 2, false, true));
            addWorldObjectAtPosition(2, 1, Villager("Bunny"));
            addEnvironmentTileAtPosition(1, 2, EnvironmentTile("welcome mat 3", 2, 2, true,  false, {'s',  2, 1, 3}));
            break;
    }
}

void Map::removeWorldObjectAtPosition(int x, int y) {
    objects.erase({x,y});
}

void Map::addWorldObjectAtPosition(int x, int y, WorldObject worldObject) {
    objects.insert_or_assign({x,y}, worldObject);
}

WorldObject* Map::getWorldObjectAtPosition(int x, int y) {
    auto search = objects.find({x,y});
    if (search == objects.end())
        return nullptr;
    return &(search->second);
}

void Map::addEnvironmentTileAtPosition(int x, int y, EnvironmentTile environmentTile) {
    environmentTiles.insert_or_assign({x,y}, environmentTile);
}

EnvironmentTile Map::getEnvironmentTileAtPosition(int x, int y) {
    auto search = environmentTiles.find({x,y});
    return search->second;
}