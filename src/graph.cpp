/*
 * GRAPH
 * Graph stuff from LeetCode
 *
 * Stefan Wong 2019
 */

#include <iostream>
#include <sstream>
#include <vector>
#include "graph.hpp"


// GraphNode implementation
GraphNode::GraphNode() : val(0), key(0) {}

GraphNode::GraphNode(int val, int key) : val(val), key(key) {} 

GraphNode::GraphNode(int val, int key, std::vector<GraphNode*> nbors)
{
    this->val = val;
    this->key = key;
    this->neighbours = nbors;
}

void GraphNode::addNeighbour(GraphNode* n)
{
    this->neighbours.push_back(n);
}

void GraphNode::init(void)
{
    this->key = 0;
    this->val = 0;
    this->neighbours.clear();
}

void GraphNode::setVal(int v)
{
    this->val = v;      // obviated somewhat by public access
}

std::string GraphNode::toString(void) const
{
    std::ostringstream oss;

    oss << "GraphNode " << this->key << "[" << this->val 
        << "]" << std::endl;
    if(this->neighbours.size() > 0)
    {
        for(unsigned int n = 0; n < this->neighbours.size(); ++n)
        {
            oss << "    -> " << this->neighbours[n]->key 
                << "[" << this->neighbours[n]->val << "]" << std::endl;
        }
    }

    return oss.str();
}


// ======== GRAPH FUNCTIONS ======== //
std::vector<std::string> graph_repr_to_token_vec(const std::string& repr)
{
    std::stringstream ss(repr);
    std::vector<std::string> token_vec;

    // first char should be a '{'
    if(repr[0] != '{')
    {
        std::cerr << "[" << __func__ << "] repr must be in the form {a,b#,...,n#} (missing '{')"
            << std::endl;
        return token_vec;
    }

    // Check here for {}, which is a valid empty graph
    if(repr.length() == 2)
    {
        if((repr[0] != '{') && (repr[1] != '}'))
            std::cerr << "[" << __func__ << "] invalid graph repr (" << repr << ")" << std::endl;

        return token_vec;       // its either a valid empty graph or an invalid empty graph...
    }

    // Tokenize whatever else we have 
    while(ss.good())
    {
        std::string substr;
        std::getline(ss, substr, '#');
        // remove leading spaces 
        if(substr[0] == ' ')
            substr = substr.substr(1, substr.length()-1);
        // strip the '{' or '}' chars 
        if(substr[0] == '{')
           substr = substr.substr(1, substr.length()-1); 
        if(substr[substr.length()-1] == '}')
            substr = substr.substr(0, substr.length()-1);
        
        token_vec.push_back(substr);
    }

	return token_vec;
}

/*
 * repr_to_graph()
 */
GraphNode* repr_to_graph(const std::string& repr)
{
    //GraphNode* graph_root;
    std::vector<std::string> token_vec;
   
    token_vec = graph_repr_to_token_vec(repr);

    // what is going on in the vector?
    std::cout << "[" << __func__ << "] token_vec contains " 
        << token_vec.size() << " tokens" << std::endl;
    for(unsigned int i = 0; i < token_vec.size(); ++i)
    {
        std::cout << "[" << __func__ << "] : " << token_vec[i] << std::endl;
    }
    
    // The repr is a string representation of an adjacency list. We 
    // iterate over the list here and create each node in turn. The
    // thing about this is.... how to do it? We have a GraphNode object
    // which contains pointers to its neighbours, and therefore we need
    // to be able to set all the neighbours correctly somehow in order to
    // make the graph....

    // TODO : debug - remove
    for(unsigned int t = 0; t < token_vec.size(); ++t)
    {
        std::cout << "[" << __func__ << "] token_vec[" << t << "] : "
            << token_vec[t] << std::endl;
    }

    // This is likely not the most efficient way, but I will do two 
    // passes here. The first constructs the correct number of nodes and 
    // places them into a vector. The second pass correctly assigns the 
    // neighbours, starting from the root node.
    std::vector<GraphNode*> nodes;   

    // first pass - create enough nodes
    for(unsigned int v = 0; v < token_vec.size(); ++v)
    {
        std::stringstream ss(token_vec[v]);
        std::string tok_substr;
        std::getline(ss, tok_substr, ',');

        // default values are 0, keys are whatever was in the repr
        GraphNode* node = new GraphNode(std::stoi(tok_substr), 0);
        nodes.push_back(node);
    }

    // Second pass - assign pointers for neighbours
    for(unsigned int v = 0; v < token_vec.size(); ++v)
    {
        std::stringstream ss(token_vec[v]);
        int tokn = 0;
        while(ss.good())
        {
            std::string tok_substr;
            std::getline(ss, tok_substr, ',');
            // For 'real' use we should try to catch exceptions here...
            if(tokn > 0)
            {
                int node_idx = std::stoi(tok_substr);   // Exception...
                nodes[v]->addNeighbour(nodes[node_idx]);
            }
            tokn++;
        }
    }

    //return graph_root;
    return nodes[0];
}

std::string graph_to_repr(const GraphNode* graph)
{
    // Iterate over the vector
    std::ostringstream oss;

    // NOTE: We need some traversal methods for this to work...

    
    return oss.str();
}

/*
 * createGraph()
 */
GraphNode* createGraph(const std::string& repr)
{
    GraphNode* graph_root;

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

    // Now parse the various sub-lists of the adjacency repr
    return repr_to_graph(repr);
}


/*
 * cloneGraph()
 */
GraphNode* cloneGraph(GraphNode* node)
{
    GraphNode* out_graph;

    return out_graph;
}




// ======== ADJACENCY MATRIX ======== ///
AdjMatrix::AdjMatrix(unsigned int v) : dim(v), adj_matrix(v+1, std::vector<int>(v+1, 0))
{
    //this->dim = v;
    //this->adj_matrix = std::vector<std::vector<int>>(this->dim, this->dim);
}

void AdjMatrix::init(void)
{
    for(unsigned int i = 0; i < this->dim; ++i)
    {
        for(unsigned int j = 0; j < this->dim; ++j) {
            this->adj_matrix[i][j] = 0;
        }
    }
}

unsigned int AdjMatrix::getDim(void) const
{
    return this->dim;
}

//void AdjMatrix::add_node(const std::vector<int>& link)
//{
//}

// operators 
// EQ
bool AdjMatrix::operator==(const AdjMatrix& that) const
{
    for(unsigned int i = 0; i < this->dim; ++i)
    {
        for(unsigned int j = 0; j < this->dim; ++j)
        {
            if(this->adj_matrix[i][j] != that.adj_matrix[i][j])
                return false;
        }
    }

    return true;
}

// NE
bool AdjMatrix::operator!=(const AdjMatrix& that) const
{
    return !(*this == that);
}



// ======== GRAPH EDGE ======== ///
GraphEdge::GraphEdge()
{
    this->init();
}

GraphEdge::GraphEdge(int key, int val)
{
    this->edge.first  = key;
    this->edge.second = val;
}

void GraphEdge::init(void)
{
    this->edge.first  = 0;
    this->edge.second = 0;
}

bool GraphEdge::operator==(const GraphEdge& that) const
{
    return (this->edge == that.edge);
}

bool GraphEdge::operator!=(const GraphEdge& that) const
{
    return (this->edge != that.edge);
}


// ======== ADJACENCY LIST ======== ///



AdjList::AdjList() 
{
    // TODO : what should the default init for the adj_list be?
}

AdjList::AdjList(const std::string& repr)
{
    std::vector<std::string> token_vec = graph_repr_to_token_vec(repr);

    // Since the repr is already an adjacency list, we just need to 
    // iterate over the token vector strings and turn each one into an 
    // element in this->adj_list
    for(unsigned int v = 0; v < token_vec.size(); ++v)
    {
        std::vector<GraphEdge> edges;
        std::stringstream ss(token_vec[v]);
        while(ss.good())
        {
            std::string tok_substr;
            std::getline(ss, tok_substr, ',');
            edges.push_back(GraphEdge(std::stoi(tok_substr), 0));
            // For 'real' use we should try to catch exceptions here...
        }
        this->adj_list.push_back(edges);
    }
}

//AdjList::AdjList(const std::vector<GraphEdge>& edges)
//{
//    // TODO :
//}

void AdjList::addEdge(const std::vector<GraphEdge>& edges)
{
    // TODO: we don't check here for any conflict with existing edges..
    this->adj_list.push_back(edges);
}


std::string AdjList::toString(void) const
{
    std::ostringstream oss;

    oss << "{";
    
    for(unsigned int e = 0; e < this->adj_list.size(); ++e)
    {
        for(unsigned int n = 0; n < this->adj_list[e].size(); ++n)
            oss << this->adj_list[e][n].edge.first << ",";
        oss << "#";
    }

    oss << "}";

    return oss.str();
}
