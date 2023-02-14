#pragma once
#include <string>

enum class Attribute {
   Dark, Divine, Earth, Fire, Light, Water, Wind
};



const std::string to_symbol(Attribute attribute) {
    switch (attribute) {
        case Attribute::Dark:
            return u8"闇";
            break;
        case Attribute::Divine:
            return u8"神";
            break;
        case Attribute::Earth:
            return u8"地";
            break;
        case Attribute::Fire:
            return u8"炎";
            break;
        case Attribute::Light:
            return u8"光";
            break;
        case Attribute::Water:
            return u8"水";
            break;
        case Attribute::Wind:
            return u8"風";
            break;

        default:
            return "";
    }
} 