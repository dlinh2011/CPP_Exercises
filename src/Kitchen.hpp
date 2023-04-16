#pragma once
#include "../lib/Unit.hpp"

#include <algorithm>
#include <cctype>
#include <list>
#include <memory>
#include <string>
#include <vector>

using UnitPtr = std::unique_ptr<Unit>;

class Kitchen
{
public:
    Unit& register_unit(Unit unit)
    {
        auto ptr = std::make_unique<Unit>(unit);
        _units.push_back(std::move(ptr));
        return *(_units.back());
    }

    Ingredient& register_ingredient(Ingredient ingredient) { return _ingredients.emplace_back(ingredient); }

    Ingredient* find_ingredient(std::string& name)
    {
        auto result =
            std::find_if(begin(_units), end(_units), [&name](UnitPtr& ptr) { return name == ptr->name; });
    }

    Unit* find_unit(const std::string& name)
    {
        auto result =
            std::find_if(begin(_units), end(_units), [&name](UnitPtr& ptr) { return name == ptr->name; });
        if (result == _units.end())
        {
            return nullptr;
        }
        return &(*(*result));
    }

private:
    struct Compare
    {};
};
