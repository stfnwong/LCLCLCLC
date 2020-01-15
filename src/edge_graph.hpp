/*
 * EDGE_GRAPH
 * Implementation of edge-weighted digraph
 * Mostly based on (https://algs4.cs.princeton.edu/44sp/)
 *
 * Stefan Wong 2020
 */

#ifndef __LC_EDGE_GRAPH_HPP
#define __LC_EDGE_GRAPH_HPP

#include <string>
#include <vector>


/*
 * Single edge in a weighted directed graph
 */
class DirectedEdge
{
    // Public until debugging is complete
    public:
        int v;
        int w;
        float weight;

    public:
        DirectedEdge();
        DirectedEdge(int v, int w, float weight);
        DirectedEdge(const DirectedEdge& that);

        // API
        float getWeight(void) const;
        int   getFrom(void) const;
        int   getTo(void) const;

        std::string toString(void) const;
};


/*
 * Represented an entire weighted directed graph
 */
class EdgeWeightedDigraph
{
    unsigned int V;
    unsigned int E;

    std::vector<DirectedEdge> verticies;
    //std::vector<int> indegree;
    
    private:
        std::vector<std::string> repr_to_tok(const std::string& repr);

    public:
        EdgeWeightedDigraph();
        EdgeWeightedDigraph(unsigned int V);
        EdgeWeightedDigraph(const std::string& repr);
        // TODO : copy ctor

        // getters 
        unsigned int numVerticies(void) const;
        unsigned int numEdges(void) const;

        // setters 
        void addEdge(const DirectedEdge& edge);
        // get all the neighbours of vertex v
        //std::vector<unsigned int> adj(unsigned int v);

        std::string toString(void) const;
};

/*
 * repr_from_file()
 * Read a graph repr from disk. The format is as per the test data 
 * in https://algs4.cs.princeton.edu/44sp/.
 */
std::string repr_from_file(const std::string& filename);


#endif /*__LC_EDGE_GRAPH_HPP*/
