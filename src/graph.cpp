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
    Node* graph_root;

    return graph_root;
}

/*
 * createGraph()
 */
Node* createGraph(const std::string& repr)
{
    Node* graph_root;

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

unsigned int AdjMatrix::get_dim(void) const
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


// ======== ADJACENCY LIST ======== ///
AdjList::AdjList() 
{
    // TODO : what should the init for the adj_list be?
}

//AdjList::AdjList(const std::vector<GraphEdge>& edges)
//{
//    // TODO :
//}
