/*
 * GRAPH
 * Graph stuff from LeetCode
 *
 * Stefan Wong 2019
 */

#ifndef __LC_GRAPH_HPP
#define __LC_GRAPH_HPP


#include <string>
#include <vector>


// Graph node 
class Node
{
    public:
        int val;
        std::vector <Node*> neighbours;

    public:
        Node();
        Node(int val, std::vector<Node*> nbors); 
};


// Create graphs from repr strings
// NOTE: repr format looks like
//
//
Node* repr_to_graph(const std::string& repr);

Node* createGraph(const std::string& repr);


// Methods that work on graph nodes
Node* cloneGraph(Node* node);


#endif /*__LC_GRAPH_HPP*/
