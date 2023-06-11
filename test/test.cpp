#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

// Include necessary headers

TEST_CASE("Shortest Path Calculation - Empty Graph") {
    // Create an empty graph
    std::vector<Node*> nodes;
    std::vector<Edge*> edges;
    Graph graph(nodes, edges);

    // Try to find the shortest path and its cost
    std::vector<Node*> shortestPath = graph.findShortestPathWithDijkstra(nullptr, nullptr);
    int pathCost = graph.getCostOfPath(shortestPath);

    // Verify the results
    REQUIRE(shortestPath.empty());
    REQUIRE(pathCost == INT_MAX);
}

TEST_CASE("Shortest Path Calculation - Single Node") {
    // Create a single node
    Node* nodeA = new Node("A");

    // Create a graph with a single node
    std::vector<Node*> nodes = {nodeA};
    std::vector<Edge*> edges;
    Graph graph(nodes, edges);

    // Try to find the shortest path and its cost
    std::vector<Node*> shortestPath = graph.findShortestPathWithDijkstra(nodeA, nodeA);
    int pathCost = graph.getCostOfPath(shortestPath);

    // Verify the results
    REQUIRE(shortestPath.size() == 1);
    REQUIRE(shortestPath[0] == nodeA);
    REQUIRE(pathCost == 0);

    // Clean up memory
    for (Node* node : nodes) {
        delete node;
    }
}

TEST_CASE("Shortest Path Calculation - Unreachable Node") {
    // Create nodes and edges
    Node* nodeA = new Node("A");
    Node* nodeB = new Node("B");
    Node* nodeC = new Node("C");
    Edge* edgeAB = new Edge(nodeA, nodeB, 1);

    // Create a graph and add nodes and edges
    std::vector<Node*> nodes = {nodeA, nodeB, nodeC};
    std::vector<Edge*> edges = {edgeAB};
    Graph graph(nodes, edges);

    // Try to find the shortest path and its cost to an unreachable node
    std::vector<Node*> shortestPath = graph.findShortestPathWithDijkstra(nodeA, nodeC);
    int pathCost = graph.getCostOfPath(shortestPath);

    // Verify the results
    REQUIRE(shortestPath.empty());
    REQUIRE(pathCost == INT_MAX);

    // Clean up memory
    for (Node* node : nodes) {
        delete node;
    }
    for (Edge* edge : edges) {
        delete edge;
    }
}

TEST_CASE("Shortest Path Calculation - Negative Edge Cost") {
    // Create nodes and edges
    Node* nodeA = new Node("A");
    Node* nodeB = new Node("B");
    Node* nodeC = new Node("C");
    Edge* edgeAB = new Edge(nodeA, nodeB, -5);
    Edge* edgeBC = new Edge(nodeB, nodeC, -3);

    // Create a graph and add nodes and edges
    std::vector<Node*> nodes = {nodeA, nodeB, nodeC};
    std::vector<Edge*> edges = {edgeAB, edgeBC};
    Graph graph(nodes, edges);

    // Find the shortest path and its cost
    std::vector<Node*> shortestPath = graph.findShortestPathWithDijkstra(nodeA, nodeC);
    int pathCost = graph.getCostOfPath(shortestPath);

    // Verify the results
    REQUIRE(shortestPath.size() == 3);
    REQUIRE(shortestPath[0]->station == "A");
    REQUIRE(shortestPath[1]->station == "B");
    REQUIRE(shortestPath[2]->station == "C");
    REQUIRE(pathCost == -8);

    // Clean up memory
    for (Node* node : nodes) {
        delete node;
    }
    for (Edge* edge : edges) {
        delete edge;
    }
}

TEST_CASE("Shortest Path Calculation - Multiple Paths with Same Cost") {
    // Create nodes and edges
    Node* nodeA = new Node("A");
    Node* nodeB = new Node("B");
    Node* nodeC = new Node("C");
    Node* nodeD = new Node("D");
    Edge* edgeAB = new Edge(nodeA, nodeB, 1);
    Edge* edgeBC = new Edge(nodeB, nodeC, 2);
    Edge* edgeBD = new Edge(nodeB, nodeD, 3);
    Edge* edgeCD = new Edge(nodeC, nodeD, 2);

    // Create a graph and add nodes and edges
    std::vector<Node*> nodes = {nodeA, nodeB, nodeC, nodeD};
    std::vector<Edge*> edges = {edgeAB, edgeBC, edgeBD, edgeCD};
    Graph graph(nodes, edges);

    // Find the shortest path and its cost
    std::vector<Node*> shortestPath = graph.findShortestPathWithDijkstra(nodeA, nodeD);
    int pathCost = graph.getCostOfPath(shortestPath);

    // Verify the results
    REQUIRE(shortestPath.size() == 3);
    REQUIRE((shortestPath[0]->station == "A" && shortestPath[1]->station == "B" && shortestPath[2]->station == "D"));
    REQUIRE(pathCost == 4);

    // Clean up memory
    for (Node* node : nodes) {
        delete node;
    }
    for (Edge* edge : edges) {
        delete edge;
    }
}

