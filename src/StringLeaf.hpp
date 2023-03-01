#pragma once
#include <string>
#include "NodeKind.hpp"
#include "Leaf.hpp"
#include <memory>
class StringLeaf : public Leaf {
    public:
        StringLeaf(const std::string& value) : _value {value} {}
        NodeKind kind() const override {
            return NodeKind::STRING;
        }
        std::string print() const override {
            return "\"" + _value + "\"";
        }
        std::string data() const {
            return _value;
        }
        static NodePtr make_ptr(std::string v) {
            return std::make_unique<StringLeaf>(v);
        }
    private:
        std::string _value;
};
