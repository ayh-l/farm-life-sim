#ifndef WORLD_OBJECT_H
#define WORLD_OBJECT_H
#include <string>

class WorldObject
{
    //TODO fields
    public:
        WorldObject();
        void setName(std::string name);
        std::string getName();
    private:
        std::string name;
};

#endif