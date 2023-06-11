#pragma once
#include <iostream>
#include <string>
#include <vector>

class Edge;

class Node {
public:
    std::string label;
    std::vector<Edge*> edges;
    int minimalDistance;

    Node(std::string label);

    friend std::ostream& operator<<(std::ostream& os, Node& node);

    struct NodeComparator {
        bool operator()(Node* lhs, Node* rhs) {
            return lhs->minimalDistance > rhs->minimalDistance;
        }
    };
};