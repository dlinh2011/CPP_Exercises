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
        void loan(int money) {
            _wealth += money;
            _debt += money + (0.1 * money);
        }
        int get_debt_amount() const {
            return _debt;
        }
        void make_plush(int cost) {
            if (_wealth == 0) return;
            if (cost > _wealth) {
                _wealth = 0; 
            }
            else {
                _wealth -= cost;
            }
            _stock++;
        }
    private: 
        std::string _name;
        int _wealth = 0;
        int _stock = 0;
        int _debt = 0; 
};
