/*
 * EDGE_GRAPH
 * Implementation of edge-weighted digraph
 * Mostly based on (https://algs4.cs.princeton.edu/44sp/)
 *
 * Stefan Wong 2020
 */

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "edge_graph.hpp"


// ======== DirectedEdge ======== //
DirectedEdge::DirectedEdge() : v(0), w(0), weight(0.0f) {} 

DirectedEdge::DirectedEdge(int v, int w, float weight) : v(v), w(w), weight(weight) {} 

// copy ctor
DirectedEdge::DirectedEdge(const DirectedEdge& that)
{
    this->v      = that.v;
    this->w      = that.w;
    this->weight = that.weight;
}

// ======== GETTERS
/*
 * weight()
 */
float DirectedEdge::getWeight(void) const
{
    return this->weight;
}

/*
 * from()
 */
int DirectedEdge::getFrom(void) const
{
    return this->v;
}

/*
 * to()
 */
int DirectedEdge::getTo(void) const
{
    return this->w;
}


/*
 * toString()
 */
std::string DirectedEdge::toString(void) const
{
    std::ostringstream oss;

    oss << "[" << this->v << "] -> [" 
        << this->w << "] : " << std::setprecision(5) 
        << this->weight; 

    return oss.str();
}


// ======== EdgeWeightedDigraph ======== //
EdgeWeightedDigraph::EdgeWeightedDigraph() : V(0), E(0) {} 
EdgeWeightedDigraph::EdgeWeightedDigraph(unsigned int v) : V(v), E(0), verticies(v+1) {}  

EdgeWeightedDigraph::EdgeWeightedDigraph(const std::string& repr)
{

}

// Processing graph repr
std::vector<std::string> EdgeWeightedDigraph::repr_to_tok(const std::string& repr)
{

}


unsigned int EdgeWeightedDigraph::numVerticies(void) const
{
    return this->V;
}

unsigned int EdgeWeightedDigraph::numEdges(void) const
{
    //return this->verticies.size();
    return this->E;
}


void EdgeWeightedDigraph::addEdge(const DirectedEdge& edge)
{
    this->verticies.push_back(edge);
}


/*
 * repr_from_file()
 * Notes on format:
 *   - first line contains number of verticies
 *   - second line is number of verticies
 *   - Each of the following lines contains (v, w, weight) tuple
 */
std::string repr_from_file(const std::string& filename)
{
    std::ifstream infile;
    std::string   line;
    std::string   repr_text;
    //int num_verticies;
    //int num_edges;

    try {
        infile.open(filename, std::ios::in);
    }
    catch(std::ios_base::failure& e) {
        std::cerr << "[" << __func__ << "] " << e.what() << std::endl;
    }

    //unsigned int cur_line = 0;
    while(std::getline(infile, line))
    {
        repr_text += line;
        repr_text.push_back('\n');
    }
    repr_text.push_back('\0');

    infile.close();

    return repr_text;
}
