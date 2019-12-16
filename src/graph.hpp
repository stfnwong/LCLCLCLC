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
#include <map>
#include <unordered_map>


// Graph node 
class GraphNode
{
    public:
        int key;
        int val;
        int uid;        // now the question is - how to generate some unique ids?
        std::vector <GraphNode*> neighbours;

    public:
        GraphNode(int uid);
        GraphNode(int uid, int val, int key);
        GraphNode(int uid, int val, int key, std::vector<GraphNode*> nbors); 

        void addNeighbour(GraphNode* n);
        void init(void);

        void setVal(int v);
        std::string toString(void) const;
};


// What about representing an entire graph?
// This is actually the implementation that is used in https://www.youtube.com/watch?v=zaBhtODEL0w (Hackerrank video)
//

/*
 * Graph
 * A Graph is a collection of Graph Nodes
 */
class Graph
{
    private:
        // this is just a lookup for traversals
        std::unordered_map<int, GraphNode> node_lut;
        // storage for internal graph nodes - this follows the implemntation for GraphAdjList in pylc/graph.py
        std::map<int, GraphNode> graph;

    private:
        void bfs_inner(int src_uid, std::vector<int>& traversal);
        void dfs_inner(int src_uid, std::vector<int>& traversal);
        void level_order_inner(std::vector<int>& traversal);

    public:
        Graph();

        void init(void);
        void addNode(const GraphNode& node);
        void removeNode(int uid);
        void addEdge(int uid, const std::vector<int>& adj);
        bool checkUnique(void) const;
        int  size(void) const;
        
        // traversal
        void bfs(int src_uid, std::vector<int>& traversal);
        void dfs(int src_uid, std::vector<int>& traversal);
        std::vector<int> levelOrder(void) const;
};



// Create graphs from repr strings
// NOTE: repr format looks like
//
// {a,b,#,b,c#}     
// where 
//  - a, b, c are the names (or keys) for various nodes
//  - # seperates an adjacency list edge for a particular node
//
std::vector<std::string> graph_repr_to_token_vec(const std::string& repr);
std::string              graph_to_repr(const GraphNode* graph);
GraphNode*               repr_to_graph_node(const std::string& repr);
GraphNode*               createGraph(const std::string& repr);

// Methods that work on graph nodes
GraphNode* cloneGraphNode(GraphNode* node);




// ==== Traversals ==== //
void graph_node_bfs(GraphNode* root, std::vector<int>& traversal);
void graph_node_dfs(GraphNode* root, std::vector<int>& traversal);



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

        unsigned int getDim(void) const;
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
//typedef std::pair<int, int> GraphEdge;
struct GraphEdge
{
    std::pair<int, int> edge;

    public:
        GraphEdge();
        GraphEdge(int key, int val);

        void init(void);

        bool operator==(const GraphEdge& that) const;
        bool operator!=(const GraphEdge& that) const;
};



// Adjacency List 
// NOTE: eventually this would become a template class
class AdjList
{
    private:
        //std::unordered_map<int, std::vector<GraphEdge>> adj_list;
        std::vector<std::vector<GraphEdge>> adj_list;


    public:
        AdjList();
        AdjList(const std::string& repr);
        // TODO: implement later
        //AdjList(const std::vector<GraphEdge>& edges);
        
        void addEdge(const std::vector<GraphEdge>& edges);
        std::string toString(void) const;

        // getters 
        unsigned int numVerticies(void) const;
};


// ======== Traversals ======== //
void adj_list_bfs(AdjList& list, std::vector<int>& traversal);
//void adj_list_dfs(AdjList& list, std::vector<int> traversal);



#endif /*__LC_GRAPH_HPP*/
