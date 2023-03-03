#pragma once
#include <vector>
#include "Card.hpp"
#include <memory>

class Board
{
public:
    bool put(std::unique_ptr<Card> card)
    {
        _board.emplace_back(std::move(card));
    }

    // doit savoir le type de card
    // dynamic cast ?

private:
    std::vector<std::unique_ptr<Card>> _board;
    // use unique_ptr parce que la mémoire peut bouger
};