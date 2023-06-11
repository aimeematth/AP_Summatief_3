#include "include/node.hpp"
Node::Node(std::string station) : station(station) {}
std::ostream& operator<<(std::ostream& os, Node& node) {
    os << "Node " << node.station << " distance " << node.minimalDistance << "\n";
    return os;
}
