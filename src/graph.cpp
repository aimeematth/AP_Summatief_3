#include "include/graph.hpp"
#include <algorithm>
#include <queue>

Graph::Graph(std::vector<Node*> nodes, std::vector<Edge*> edges) : nodes(std::move(nodes)), edges(std::move(edges)) {}

Edge* Graph::getEdgeBetweenNodes(Node* from, Node* to) {
    for (Edge* edge : from->edges) {
        if (edge->to == to) {
            return edge;
        }
    }
    return nullptr;
}

int Graph::getCostOfPath(std::vector<Node*> nodesToVisit) {
    int totalCosts = 0;
    for (int i = 0; i < nodesToVisit.size() - 1; i++) {
        totalCosts += getEdgeBetweenNodes(nodesToVisit[i], nodesToVisit[i + 1])->cost;
    }
    return totalCosts;
}

std::vector<Node*> Graph::findShortestPathWithDijkstra(Node* start, Node* end) {
    std::priority_queue<Node*, std::vector<Node*>, Node::NodeComparator> pq;
    for (Node* node : nodes) {
        node->minimalDistance = (node == start) ? 0 : INT_MAX;
        pq.push(node);
    }

    while (!pq.empty()) {
        Node* current = pq.top();
        pq.pop();

        if (current == end) {
            break;
        }

        for (Edge* edge : current->edges) {
            int newDistance = current->minimalDistance + edge->cost;
            if (newDistance < edge->to->minimalDistance) {
                edge->to->minimalDistance = newDistance;
                pq.push(edge->to);
            }
        }
    }

    std::vector<Node*> shortestPath;
    Node* current = end;
    while (current != nullptr) {
        shortestPath.insert(shortestPath.begin(), current);
        Edge* minEdge = nullptr;
        for (Edge* edge : current->edges) {
            if (edge->to->minimalDistance == current->minimalDistance - edge->cost) {
                minEdge = edge;
                break;
            }
        }
        current = (minEdge != nullptr) ? minEdge->from : nullptr;
    }

    return shortestPath;
}