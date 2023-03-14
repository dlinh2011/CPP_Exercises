#pragma once
#include <vector>
#include "../lib/Unit.hpp"
#include "../lib/Ingredient.hpp"
#include <string>
#include <memory>
#include <algorithm>

using UnitPtr = std::unique_ptr<Unit>;
using IngredientPtr = std::unique_ptr<Ingredient>;

class Kitchen
{
    public: 
        const Unit& register_unit(const Unit& new_unit){
            _units.push_back(std::make_unique<Unit>(new_unit));
            return *_units.back();
        }
        const Unit* find_unit(const std::string& name) const {
            /* auto first = _units.begin();
            auto last = _units.end();
            for (; first != last; ++first)
                if ((**first).name == name) {
                    return *first;
                }
            return nullptr; */
            auto is_name = [name](const UnitPtr& p){ return p->name == name; };
            // observator
            // gagner pas l'ownership
            auto it = std::find_if(begin(_units), end(_units), is_name); 
            if (it == end(_units)) {
                return nullptr;
            }
            return it->get();
        }

        const Ingredient& register_ingredient(const Ingredient& new_ing){
            _ingredients.push_back(std::make_unique<Ingredient>(new_ing));
            return *_ingredients.back();
        }

        const Ingredient* find_ingredient(std::string name) const {
           /* auto it1 = std::transform(name.begin(), name.end(), name.begin(),
            [](unsigned char c){ return std::tolower(c); });

            std::string expectsString(1, *it1); */
            auto is_name = [name](const IngredientPtr& p){ return p->name == name; };

            auto it = std::find_if(begin(_ingredients), end(_ingredients), is_name); 
            if (it == end(_ingredients)) {
                return nullptr;
            }
            return it->get();
        }





        
    std::vector<UnitPtr> _units; 
    std::vector<IngredientPtr> _ingredients; 
};
