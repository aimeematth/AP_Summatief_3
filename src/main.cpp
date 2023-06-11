#include <iostream>
#include <queue>
#include "include/node.hpp"
#include "include/edge.hpp"
#include "include/graph.hpp"


int main(){

//Priority queue with integers
std::priority_queue<int> pq;
pq.push(10);
pq.push(5);
pq.push(7);

while(!pq.empty()){
    std::cout << pq.top() <<"\n";
    pq.pop();
}


//min-heap priority queue with Nodes
std::priority_queue<Node*, std::vector<Node*>, Node::NodeComparator> pq_nodes;

Node a = Node("A");
Node b = Node("B");
Node c = Node("C");

a.minimalDistance = 0;
b.minimalDistance = 10;
c.minimalDistance = 5;

pq_nodes.push(&a);
pq_nodes.push(&b);
pq_nodes.push(&c);


while(!pq_nodes.empty()){
    Node* n = pq_nodes.top();
    std::cout << *n << "\n"; //werkt omdat we operator<< hebben geimplementeerd in node.cpp
    pq_nodes.pop();
}

//Voorbeeld nullpointer: als je een attribuut van een nullptr opvraagt krijg je een segmentation fault

// Node* n = nullptr;
// std::cout << n->label;

}


Graph makeGraph(){
    //Hier maken we de Nodes van de voorbeeld graaf aan. Deze graaf lijkt op die in de slides, maar is directed.

    Node a = Node("a"); Node b = Node("b"); Node c = Node("c"); Node d = Node("d"); Node e = Node("e"); Node f = Node("f");
    
    //Nadat we de Nodes hebben, kunnen we de edges tussen de nodes aanmaken
    Edge a1 = Edge(&a, &b, 4); Edge a2 = Edge(&a, &c, 3);    
    Edge b1 = Edge(&b, &c, 5); Edge b2 = Edge(&b, &d, 2);
    Edge c1 = Edge(&c, &d, 3); Edge c2 = Edge(&c, &e, 1);    
    Edge d1 = Edge(&d, &f, 1); 
    Edge e1 = Edge(&e, &d, 1); Edge e2 = Edge(&e, &f, 3);   

    //Dan voegen de we edges weer toe aan het vector<Edge*> edges attribuut van de nodes.
    a.edges.push_back(&a1); 
    a.edges.push_back(&a2);
    
    b.edges.push_back(&b1);
    b.edges.push_back(&b2);
    c.edges.push_back(&c1);
    c.edges.push_back(&c2);
    d.edges.push_back(&d1);
    e.edges.push_back(&e1);
    e.edges.push_back(&e1);

    //We verzamelen de nodes en edges in een graph object.
    Graph g = Graph(
        {&a, &b, &c, &d, &e, &f},
        {&a1, &a2, &b1, &b2, &c1, &c2, &d1, &e1, &e2}
    );

    return g;
}