#pragma once
#include "Leaf.hpp"
#include <memory>
class IntLeaf : public Leaf {
    public:
        IntLeaf(int value) : _value {value} {}
        NodeKind kind() const override {
            return NodeKind::INT;
        }
        std::string print()const override {
            return std::to_string(_value);
        }
        int data() const {
            return _value;
        }
        static NodePtr make_ptr(int v) {
        return std::make_unique<IntLeaf>(v);
        }
    private:
        int _value;
};

