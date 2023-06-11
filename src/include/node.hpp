#pragma once
#include <iostream>
#include <string>
#include <vector>

class Edge;

class Node {
public:
    std::string station;
    std::vector<Edge*> edges;
    int minimalDistance;

    Node(std::string station);

    friend std::ostream& operator<<(std::ostream& os, Node& node);

    struct NodeComparator {
        bool operator()(Node* lhs, Node* rhs) {
            return lhs->minimalDistance > rhs->minimalDistance;
        }
    };
};