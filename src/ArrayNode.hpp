#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"
#include <memory>
#include <vector>
#include <string>
class ArrayNode : public Node {
    public:
        NodeKind kind() const override {
            return NodeKind::ARRAY;
        }
        std::string print() const override {
            std::string str = "[";
            std::string sep = "";
            for (const auto& nodePtr : _values) {
                str += sep + nodePtr->print();
                sep = ",";
            }
            return str + "]";
        }
        static std::unique_ptr<ArrayNode> make_ptr(){
            return std::make_unique<ArrayNode>();
        }
        int child_count() const {
            return _values.size();
        }
        unsigned int height() const override { 
            auto max_height = 0u;          
            for (const auto& nodePtr : _values) {
                auto node_height = nodePtr->height();
                if (node_height > max_height) {
                    max_height = node_height;
                }
            }
            if (child_count() > 0) {
                max_height++;
            }
            return max_height;
        }
        unsigned int node_count() const override { 
            auto count = 1u;          
            for (const auto& nodePtr : _values) {
                count += nodePtr->node_count();
            }
            return count;
        }
        void push_back(NodePtr node) {
            // créer un nouveau object NodePtr et faire un move dedans
            _values.push_back(std::move(node)); // std::move parce qu'on est en train de faire un copy
        }
    private:
        std::vector<NodePtr> _values;
};
