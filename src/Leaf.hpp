#pragma once
#include "Node.hpp"
#include <string>
class Leaf : public Node {
    public: 
    unsigned int height() const override {
            return 0; 
    }
    unsigned int node_count() const override {
            return 1; 
    }
};