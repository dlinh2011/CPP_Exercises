#pragma once
#include <string>
#include "Card.hpp"

enum class Attribute {
   Dark, Divine, Earth, Fire, Light, Water, Wind
};

class Monster : public Card {
    public: 
        Monster(const std::string& id, const std::string& name,Attribute attribute, const std::string& description, int atk, int def) 
        : Card {id, CardType::Monster},  _attribute { attribute} , _atk {atk} , _def {def} 
        {
            set_name(name);
            set_description(description);
        }
        Attribute get_attribute() const {
            return _attribute;
        }
        int get_atk() const {
            return _atk;
        }
        int get_def() const {
            return _def;
        }
    private:
        Attribute _attribute; 
        int _atk = 0; 
        int _def = 0;
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