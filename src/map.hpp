#ifndef MAP_H
#define MAP_H

#include "worldobject.hpp"
#include "environment_tile.hpp"
#include "navigator.hpp"
#include <utility>
#include <string>
#include <unordered_map>

class Map
{
    public:
        Map(int mapId);
        void removeWorldObjectAtPosition(int x, int y); //operates on current map
        void addWorldObjectAtPosition(int x, int y, WorldObject worldObject);
        WorldObject* getWorldObjectAtPosition(int x, int y);

        void addEnvironmentTileAtPosition(int x, int y, EnvironmentTile environmentTile);
        EnvironmentTile getEnvironmentTileAtPosition(int x, int y);
    
    private:
        std::unordered_map<std::pair<int,int>, WorldObject> objects;
        std::unordered_map<std::pair<int,int>, EnvironmentTile> environmentTiles;
        int width;
        int height;
};

#endif