#pragma once
#include "InstanceCounter.hpp"
#include "NodeKind.hpp"
#include <memory>


class Node;
using NodePtr = std::unique_ptr<Node>;
class IntLeaf; // déclarer, il est ailleurs
class Node : public InstanceCounter {
    public: 
        virtual NodeKind kind() const = 0;
        virtual std::string print() const = 0;
        //virtual ~Node() = 0; 
        virtual unsigned int height() const = 0;
        virtual unsigned int node_count() const = 0; 
        IntLeaf* as_IntLeaf();

};