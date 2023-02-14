#pragma once
#include "Card.hpp"
enum class SpellType {
    Normal, Equip, Continuous, QuickPlay, Field
};
Sp
class Spell : public Card {
    public:

    
    private:
};

std::string to_string(SpellType type) {
    switch (type) {
S            return "Normal";
            break;
        case SpellType::Equip:
            return "Equip";
            break;
        case SpellType::Continuous:
            return "Continuous";
            break;
        case SpellType::QuickPlay:
            return "Quick-Play";
            break;
        case SpellType::Field: 
            return "Field";
            break; 
        default:
            return "";
    }
} 