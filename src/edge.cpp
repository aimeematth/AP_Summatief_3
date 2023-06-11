#include "include/edge.hpp"
#include "include/stap.hpp"

Edge::Edge(Node* from, Node* to, Stap* cost) : from(from), to(to), cost(cost) {}

std::ostream &operator<<(std::ostream &os, Edge& edge) {

    os <<  "( " << edge.from->label << "->" << edge.to->label << ")" << "\n";
    return os;
}