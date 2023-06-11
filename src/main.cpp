
#include "include/graph.hpp"
#include "include/node.hpp"
#include "include/edge.hpp"
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

    // Create some edges
    Edge* edgeAB = new Edge(nodeA, nodeB, (new Auto(10))->getKosten());
    Edge* edgeAC = new Edge(nodeA, nodeC, (new Treinrit(5))->getKosten());
    Edge* edgeBD = new Edge(nodeB, nodeD, (new Vlucht(50))->getKosten());
    Edge* edgeCD = new Edge(nodeC, nodeD, (new Auto(20))->getKosten());

    // Create a graph and add nodes and edges
    std::vector<Node*> nodes = {nodeA, nodeB, nodeC, nodeD};
    std::vector<Edge*> edges = {edgeAB, edgeAC, edgeBD, edgeCD};
    Graph graph(nodes, edges);

    // Perform some operations on the graph
    std::vector<Node*> shortestPath = graph.findShortestPathWithDijkstra(nodeA, nodeD);
    int pathCost = graph.getCostOfPath(shortestPath);

    // Display the shortest path and the cost
    std::cout << "Shortest Path: ";
    for (Node* node : shortestPath) {
        std::cout << node->label << " ";
    }
    std::cout << std::endl;
    std::cout << "Path Cost: " << pathCost << std::endl;
    return 0;
};
