#pragma once
#include "Card.hpp"
#include <string>
enum class TrapType
{
    Normal,
    Continuous,
    Counter
};

class Trap : public Card
{
public:
    Trap(const std::string &id, const std::string &name, TrapType type) : Card{id, CardType::Trap}, _trap_type{type}
    {
        set_name(name);
        _symbol = u8"罠";
    }

    TrapType get_trap_type() const { return _trap_type; }

private:
    TrapType _trap_type;
};

std::string to_string(TrapType type)
{
    switch (type)
    {
    case TrapType::Normal:
        return "Normal";
        break;
    case TrapType::Continuous:
        return "Continuous";
        break;
    case TrapType::Counter:
        return "Counter";
        break;
    default:
        return "";
    }
}