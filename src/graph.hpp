/*
 * GRAPH
 * Graph stuff from LeetCode
 *
 * Stefan Wong 2019
 */

#ifndef __LC_GRAPH_HPP
#define __LC_GRAPH_HPP

#include <memory>
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>


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




// Adjacency Matrix 
class AdjMatrix
{
    private:
        unsigned int dim;

    public:
        std::vector<std::vector<int>> adj_matrix;

    public:
        AdjMatrix(unsigned int v);
        void init(void);

        unsigned int get_dim(void) const;
        //void add_node(const std::vector<int>& link);

        // Operators 
        bool operator==(const AdjMatrix& that) const;
        bool operator!=(const AdjMatrix& that) const;
};

/*
 * GraphEdge
 * Typedef'd pair that represents an edge in a graph
 * For the moment I will use negative values to indicate null/termination, and therefore the values 
 * of the nodes in the graph must always be positive. Clearly this isn't going to scale for very large 
 * graphs.
 */
typedef std::pair<int, int> GraphEdge;

// Adjacency List 
// TODO: eventually this would become a template class
class AdjList
{
    private:
        //std::unordered_map<int, std::vector<GraphEdge>> adj_list;
        std::vector<std::vector<GraphEdge>> adj_list;

    public:
        AdjList();
        // TODO: implement later
        //AdjList(const std::vector<GraphEdge>& edges);

};



#endif /*__LC_GRAPH_HPP*/
