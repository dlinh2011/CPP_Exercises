#include "Pokemon.h"
#include <iostream>

int my_id = 0; 

Pokemon::Pokemon(const std::string& name) : _name { name }, _id { my_id } {
    my_id++; 
}

Pokemon::Pokemon(const Pokemon& other) : _name { other._name } {
}
Pokemon& Pokemon::operator=(const Pokemon& other) {
            // when this is alrealdy exist
    if (this == &other)
        return *this;
    this->_name = other._name;
    return *this;
}



