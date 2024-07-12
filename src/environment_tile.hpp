#ifndef ENVIRONMENT_TILE_H
#define ENVIRONMENT_TILE_H

#include <string>

class EnvironmentTile
{
    public:
    //TODO image
        EnvironmentTile(std::string name, int tilled, int watered, bool walkable, bool fishable);
        void till();
        void water();
        bool walkable();
        bool fishable();
        int watered(); // 0-no, 1-yes, 2-not waterable
        int tilled(); // 0-no, 1-yes, 2-not tillable

    private:
    //TODO
};

#endif