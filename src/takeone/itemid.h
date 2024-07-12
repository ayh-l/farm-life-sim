#ifndef ITEM_ID_H
#define ITEM_ID_H

#include <string>

class ItemId
{
    public:
        ItemId(std::string item_id);
        void crop_water(); //only waters if crop is alive
        void crop_pass_day();
        bool crop_is_alive();
        void soil_cultivate();
        std::string get_item_id();
    private:
        std::string item_id; // IIIICCC [item id][crop info]
};

#endif