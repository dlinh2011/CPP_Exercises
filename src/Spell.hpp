#pragma once
#include "Card.hpp"
#include <string>
enum class SpellType
{
    Normal,
    Equip,
    Continuous,
    QuickPlay,
    Field
};
class Spell : public Card
{
public:
    Spell(const std::string &id, const std::string &name, SpellType type) : Card{id, CardType::Spell}, _spell_type{type}
    {
        set_name(name);
        _symbol = u8"魔";
    }
    SpellType get_spell_type() const
    {
        return _spell_type;
    }

private:
    SpellType _spell_type;
};

std::string to_string(SpellType type)
{
    switch (type)
    {
    case SpellType::Normal:
        return "Normal";
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