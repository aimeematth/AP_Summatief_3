#include "include/graph.hpp"
#include "include/node.hpp"
#include "include/edge.hpp"
#include "include/stap.hpp"
#include "include/autorit.hpp"
#include "include/treinrit.hpp"
#include "include/vlucht.hpp"
#include <iostream>
#include <vector>

int main() {
    // Create some nodes
    Node* nodeA = new Node("A");
    Node* nodeB = new Node("B");
    Node* nodeC = new Node("C");
    Node* nodeD = new Node("D");

    // Create some stap instances
    Stap* autoStep = new Auto(10);
    Stap* treinritStep = new Treinrit(5);
    Stap* vluchtStep = new Vlucht(50);

    // Create a graph and add nodes and edges
    std::vector<Node*> nodes = {nodeA, nodeB, nodeC, nodeD};
    std::vector<Edge*> edges = {
        new Edge(nodeA, nodeB, autoStep),
        new Edge(nodeA, nodeC, treinritStep),
        new Edge(nodeB, nodeD, vluchtStep),
        new Edge(nodeC, nodeD, autoStep)
    };
    Graph graph(nodes, edges);

    // Perform some operations on the graph
    std::vector<Node*> shortestPath = graph.findShortestPathWithDijkstra(nodeA, nodeD);
    int pathCost = graph.getCostOfPath(shortestPath);

    // Display the shortest path and the cost
    std::cout << "Shortest Path: ";
    for (Node* node : shortestPath) {
        std::cout << node->label() << " ";
    }
    std::cout << std::endl;
    std::cout << "Path Cost: " << pathCost << std::endl;

    delete autoStep;
    delete treinritStep;
    delete vluchtStep;
    delete nodeA;
    delete nodeB;
    delete nodeC;
    delete nodeD;

    for (Edge* edge : edges) {
        delete edge;
    }

    return 0;
}
