#pragma once
#include <string>
enum class CardType
{
    Monster,
    Spell,
    Trap
};

class Card
{
public:
    Card(const std::string &id, CardType type) : _id{id}, _type{type} {}
    const std::string &get_id() const
    {
        return _id;
    }
    CardType get_type() const
    {
        return _type;
    }
    const std::string &get_name() const
    {
        return _name;
    }
    void set_name(const std::string &name)
    {
        _name = name;
    }
    const std::string &get_description() const
    {
        return _description;
    }
    void set_description(const std::string &description)
    {
        _description = description;
    }

    const std::string &get_symbol() const
    {
        return _symbol;
    }

protected:
    std::string _symbol;

private:
    std::string _id;
    std::string _name;
    std::string _description;
    CardType _type;
};

std::string to_string(CardType type)
{
    switch (type)
    {
    case CardType::Monster:
        return "Monster";
        break;
    case CardType::Spell:
        return "Spell";
        break;
    case CardType::Trap:
        return "Trap";
        break;
    default:
        return "";
    }
}
