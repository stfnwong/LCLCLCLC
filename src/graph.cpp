/*
 * GRAPH
 * Graph stuff from LeetCode
 *
 * Stefan Wong 2019
 */

#include <iostream>
#include "graph.hpp"


// Node implementation
Node::Node() {} 

Node::Node(int val, std::vector<Node*> nbors)
{
    this->val = val;
    this->neighbours = nbors;
}


/*
 * repr_to_graph()
 */
Node* repr_to_graph(const std::string& repr)
{
    Node* graph root;

    return graph_root;
}

/*
 * createGraph()
 */
Node* createGraph(const std::string& repr)
{
    Node* graph root;

    // do the various basic sanity checks 
    if(repr.length() < 1)
        return nullptr;

    // {}  is a valid repr, and corresponds to an empty graph
    if(repr.length() == 2)
    {
        if(repr[0] == '{' && repr[1] == '}')
            return nullptr;
        else
        {
            std::cout << "[" << __func__ << "] invalid repr " << repr << std::endl;
            return nullptr;
        }
    }

    return graph_root;
}


/*
 * cloneGraph()
 */
Node* cloneGraph(Node* node)
{

}
