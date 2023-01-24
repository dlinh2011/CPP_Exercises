#pragma once
#include <string>
#include <algorithm>
#include <vector> 
#include <optional>
#include <Plush.hpp>

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
        int get_experience() const {
            return _exp;
        }
        int make_plush(int cost) {
            if (_wealth == 0) return 0;
            if (cost > _wealth) 
                _wealth = 0; 
            else 
                _wealth -= cost;
            _stock++;
            _exp++;
            auto v_plush = value_plush(cost);
            _plushes.emplace_back(Plush { v_plush});
            std::sort(_plushes); // sais pas si ça marche
            return v_plush;
        }

        std::optional<Plush> buy(int money) {

        }


    private: 
        std::string _name;
        std::vector<Plush> _plushes; 
        int _wealth = 0;
        int _stock = 0;
        int _debt = 0; 
        int _exp = 0;

        int value_plush(int value_invest) const {
            return value_invest + std::max(_exp, _exp * value_invest / 100);
        }

};

bool operator<(const Plush& a, const Plush& b)
{
    return a.get_cost() < b.get_cost();
}

