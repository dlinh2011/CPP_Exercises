#pragma once

#include <string>

#include <memory>
using PokemonPtr = std::unique_ptr<Pokemon>;

// A creature that is cute and can fight other ones.
class Pokemon
{
    public:
    Pokemon(const std::string& name );
    Pokemon(const Pokemon& other); // when this doesn't exist
    std::string name() const {
        return _name;
    };
    int id() const {
        return _id;
    };
    Pokemon& operator=(const Pokemon& other);

    private:
    std::string _name;
    int _id; 
};
