#pragma once
#include "node.hpp"

class Edge {
    public:
        Node* from;
        Node* to;
        Stap* cost;

    Edge(Node* from, Node* to, Stap* cost);

    friend std::ostream &operator<<(std::ostream& os, Edge& edge);
};