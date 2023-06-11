#include <iostream>
#include <vector>
#include "include/graph.hpp"
#include "include/node.hpp"
#include "include/edge.hpp"
#include "include/autorit.hpp"
#include "include/treinrit.hpp"
#include "include/vlucht.hpp"

int main() {
    // Create some nodes
    Node* nodeUtrecht = new Node("Utrecht");
    Node* nodeAmersfoort = new Node("Amersfoort");
    Node* nodeEnschede = new Node("Enschede");
    Node* nodeAmsterdam = new Node("Amsterdam");
    Node* nodeMarseille = new Node("Marseille");
    Node* nodeBrussel = new Node("Brussel");
    Node* nodeMaastricht = new Node("Maastricht");

    // Create some edges
    Edge* edgeUtrechtAmersfoort = new Edge(nodeUtrecht, nodeAmersfoort, (new Auto(10))->getKosten());
    Edge* edgeUtrechtEnschede = new Edge(nodeUtrecht, nodeEnschede, (new Treinrit(20))->getKosten());
    Edge* edgeAmersfoortAmsterdam = new Edge(nodeAmersfoort, nodeAmsterdam, (new Auto(15))->getKosten());
    Edge* edgeAmsterdamBrussel = new Edge(nodeAmsterdam, nodeBrussel, (new Vlucht(100))->getKosten());
    Edge* edgeAmersfoortMaastricht = new Edge(nodeAmersfoort, nodeMaastricht, (new Treinrit(30))->getKosten());
    Edge* edgeMaastrichtMarseille = new Edge(nodeMaastricht, nodeMarseille, (new Vlucht(200))->getKosten());

    // Create a graph and add nodes and edges
    std::vector<Node*> nodes = {nodeUtrecht, nodeAmersfoort, nodeEnschede, nodeAmsterdam, nodeMarseille, nodeBrussel, nodeMaastricht};
    std::vector<Edge*> edges = {edgeUtrechtAmersfoort, edgeUtrechtEnschede, edgeAmersfoortAmsterdam, edgeAmsterdamBrussel, edgeAmersfoortMaastricht, edgeMaastrichtMarseille};
    Graph graph(nodes, edges);

    // Perform some operations on the graph
    std::vector<Node*> shortestPath = graph.findShortestPathWithDijkstra(nodeUtrecht, nodeMarseille);
    int pathCost = graph.getCostOfPath(shortestPath);

    // Display the shortest path and the cost
    std::cout << "Shortest Path: ";
    for (Node* node : shortestPath) {
        std::cout << node->station << " ";
    }
    std::cout << std::endl;
    std::cout << "Path Cost: " << pathCost << std::endl;

    // Cleanup memory
    for (Node* node : nodes) {
        delete node;
    }

    for (Edge* edge : edges) {
        delete edge;
    }

    return 0;
}
