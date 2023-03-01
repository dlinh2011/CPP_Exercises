#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"
#include <memory>
#include <map>
#include <string>
class ObjectNode : public Node {
    public:
        NodeKind kind() const override {
            return NodeKind::OBJECT;
        }
        std::string print() const override {
            std::string str = "{";
            std::string sep = "";
            for (const auto& [key, nodePtr] : _dict) {
                str += sep + "\""+ key + "\"" + ":" + nodePtr->print();
                sep = ",";
            }
            return str + "}";
        }
        static std::unique_ptr<ObjectNode> make_ptr(){
            return std::make_unique<ObjectNode>();
        }
        int child_count() const{
            return _dict.size();
        }
        void insert(std::string key, NodePtr node) {
            _dict.try_emplace(key, std::move(node));
        }
        unsigned int height() const override { 
            auto max_height = 0u;          
            for (const auto& [key, nodePtr] : _dict) {
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
            for (const auto& [key, nodePtr] : _dict) {
                count += nodePtr->node_count();
            }
            return count;
        }
    private: 
        std::map<std::string, NodePtr> _dict; 

};