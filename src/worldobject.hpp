/**
 * @file worldobject.hpp
 * Definition of the WorldObject class.
 */

#ifndef WORLD_OBJECT_H
#define WORLD_OBJECT_H
#include <string>

class WorldObject
{
    public:

        /**
         * Constructs a WorldObject with default name.
         */
        WorldObject();

        /**
         * Sets name of WorldObject as specified.
         * 
         * @param name desired name of WorldObject
         */
        void setName(std::string name);

        /**
         * Returns name of WorldObject
         * 
         * @return name of WorldObject
         */
        std::string getName();

    private:
    
        std::string name;
};

#endif