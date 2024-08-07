#ifndef ENVIRONMENT_TILE_H
#define ENVIRONMENT_TILE_H

#include <string>
#include <tuple>
#include <optional>

class EnvironmentTile
{
    public:
    //TODO image
        EnvironmentTile(std::string name, int tilled, int watered, bool walkable, bool fishable);
        EnvironmentTile(std::string name, int tilled, int watered, bool walkable, bool fishable, std::tuple<char,int,int,int> pathTo);
        void till();
        void water();
        bool isWalkable();
        bool isFishable();
        bool isWatered();
        bool isTilled();
        bool isPath();
        char directionOfPath();
        int pathLeadsToMapId();
        std::pair<int,int> pathLeadsToPosition();
        std::string getName();

    private:
        int watered; // 0-no, 1-yes, 2-not waterable
        int tilled; // 0-no, 1-yes, 2-not waterable
        bool walkable;
        bool fishable;
        std::optional<std::tuple<char,int,int,int> > pathTo; //< direction of path , mapId , xpos on map given by mapId , ypos on map.. >
        std::string name;
};

#endif