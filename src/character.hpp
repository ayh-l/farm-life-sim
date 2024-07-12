#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{
    public:
        Character(); //default name is "Luca"
        void setName(std::string name);
        std::string getName();
    private:
    //TODO fields
};

#endif