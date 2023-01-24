#pragma once
#include <string>

class PlushStore {
    public:
        PlushStore (std::string name) : _name {name} {}
        std::string get_name() const {
            return _name;
        }
        int get_wealth_amount() const {
            return _wealth; 
        }
        int get_stock_size() const {
            return _stock;
        }
    private: 
        std::string _name;
        int _wealth = 0;
        int _stock = 0; 
};
