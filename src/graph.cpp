/*
 * GRAPH
 * Graph stuff from LeetCode
 *
 * Stefan Wong 2019
 */

#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <unordered_set>
#include "graph.hpp"


// GraphNode implementation
GraphNode::GraphNode(int uid) : uid(uid), val(0) {}

GraphNode::GraphNode(int uid, int val) : uid(uid), val(val) {} 

GraphNode::GraphNode(int uid, int val, std::vector<GraphNode*> nbors)
{
    this->uid = uid;
    this->val = val;
    this->neighbours = nbors;
}

// Operators 
bool GraphNode::operator==(const GraphNode& that) const
{
    if(this->uid != that.uid)
        return false;
    if(this->val != that.val)
        return false;
    return true;
}

bool GraphNode::operator!=(const GraphNode& that) const
{
    return !(*this == that);
}

void GraphNode::addAdj(GraphNode* n)
{
    this->neighbours.push_back(n);
}

void GraphNode::init(void)
{
    this->uid = 0;  // NOTE: there aren't any actual checks for uniqueness
    this->val = 0;
    this->neighbours.clear();
}

void GraphNode::setVal(int v)
{
    this->val = v;      // obviated somewhat by public access
}

unsigned int GraphNode::numAdj(void) const
{
    return this->neighbours.size();
}


/*
 * toString()
 */
std::string GraphNode::toString(void) const
{
    std::ostringstream oss;

    oss << "GraphNode <" << this->uid << "> [" << this->val 
        << "]";
    if(this->neighbours.size() > 0)
    {
        for(unsigned int n = 0; n < this->neighbours.size(); ++n)
        {
            oss << " -> " << this->neighbours[n]->uid
                << "[" << this->neighbours[n]->val << "]";
        }
    }

    return oss.str();
}

// ======== GRAPH CLASS ======== //
Graph::Graph() {}       // not sure what to do yet...

// Private functions for traversal
void Graph::bfs_inner(int src_uid, std::vector<int>& traversal)
{
    GraphNode* cur_node;
    std::queue<GraphNode*> bfs_q;
    std::unordered_set<GraphNode*> visited_nodes;

    bfs_q.push(this->graph[src_uid]);

    while(!bfs_q.empty())
    {
        cur_node = bfs_q.front();
        bfs_q.pop();

        visited_nodes.insert(cur_node);
        traversal.push_back(cur_node->uid);

        // visit the children of this node
        for(unsigned int n = 0; n < cur_node->neighbours.size(); ++n)
        {
            if(visited_nodes.count(cur_node->neighbours[n]) == 0)
            {
                bfs_q.push(this->graph[cur_node->neighbours[n]->uid]);
            }
        }
    }
}

void Graph::dfs_inner(int src_uid, std::vector<int>& traversal, std::unordered_set<GraphNode*>& visited)
{
    GraphNode* cur_node;
    traversal.push_back(src_uid);

    cur_node = this->graph[src_uid];

    for(unsigned int n = 0; n < cur_node->neighbours.size(); ++n)
    {
        if(visited.count(cur_node->neighbours[n]) == 0)
        {
            visited.insert(cur_node->neighbours[n]);
            this->dfs_inner(cur_node->neighbours[n]->uid, traversal, visited);
        }
    }
}

/*
 * init()
 */
void Graph::init(void)
{
    this->graph.clear();
    this->node_lut.clear();
}


/*
 * addNode()
 */
void Graph::addNode(GraphNode* node)
{
    this->graph.insert(
            std::pair<int, GraphNode*>(int(this->size()), node)
    );
}

/*
 * removeNode()
 */
void Graph::removeNode(int uid)
{
    if(this->graph.count(uid) > 0)
        this->graph.erase(uid);
}

// TODO : addEdge()

/*
 * checkUnique()
 */
bool Graph::checkUnique(void) const
{
    std::unordered_set<int> uids;

    for(auto it = this->graph.begin(); it != this->graph.end(); ++it)
    {
        if(uids.count(it->second->uid) == 0)
            uids.insert(it->second->uid);
        else
            return false;
    }

    return true;
}

/*
 * size()
 */
int Graph::size(void) const
{
    return this->graph.size();
}

/*
 * get()
 */
GraphNode* Graph::get(int uid)
{
    if(this->graph.count(uid) == 0)
        return nullptr;

    return this->graph.at(uid);
}

/*
 * getIds()
 */
std::vector<int> Graph::getIds(void) const
{
    std::vector<int> ids;

    for(auto it = this->graph.begin(); it != this->graph.end(); ++it)
    {
        ids.push_back(it->first);
    }

    return ids;
}

// Traversals 

/*
 * bfs()
 */
std::vector<int> Graph::bfs(int src_uid)
{
    std::vector<int> traversal;

    if(this->graph.count(src_uid) == 0)
        return traversal;

    this->bfs_inner(src_uid, traversal);

    return traversal;
}

std::vector<int> Graph::dfs(int src_uid)
{
    std::vector<int> traversal;
    std::unordered_set<GraphNode*> visited;

    if(this->graph.count(src_uid) == 0)
        return traversal;

    this->dfs_inner(src_uid, traversal, visited);

    return traversal;
}

/*
 * toString()
 */
std::string Graph::toString(void) const
{
    std::ostringstream oss;

    oss << "Graph (" << this->size() << " nodes)" << std::endl;

    for(auto it = this->graph.begin(); it != this->graph.end(); ++it)
    {
        oss << "    " << it->second->toString() << std::endl;
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
 * repr_to_graph_node()
 */
GraphNode* repr_to_graph_node(const std::string& repr)
{
    // The repr is a string representation of an adjacency list. We 
    // iterate over the list here and create each node in turn. The
    // thing about this is.... how to do it? We have a GraphNode object
    // which contains pointers to its neighbours, and therefore we need
    // to be able to set all the neighbours correctly somehow in order to
    // make the graph....
    std::vector<std::string> token_vec;
    token_vec = graph_repr_to_token_vec(repr);

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
                nodes[v]->addAdj(nodes[node_idx]);
            }
            tokn++;
        }
    }

    return nodes[0];
}


/*
 * graph_to_repr()
 */
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

    // {}  is a valid repr, and corresponds to an empty graph (which
    // is returned as null). If its an invalid repr, we also return null
    if(repr.length() == 2)
    {
        if(repr[0] == '{' && repr[1] == '}')
            return nullptr;

        std::cout << "[" << __func__ << "] invalid repr " 
            << repr << std::endl;
        return nullptr;
    }
    // Now parse the various sub-lists of the adjacency repr
    return repr_to_graph_node(repr);
}


/*
 * cloneGraphNode()
 */
GraphNode* cloneGraphNode(GraphNode* root)
{
    GraphNode* out_graph;
    GraphNode* cur_node;
    // keep track of current nodes
    std::map<GraphNode*, GraphNode*> node_map;
    std::queue<GraphNode*>           node_q;

    if(root == nullptr)
        return nullptr;

    // BFS over the graph, copy each node as we see it.
    node_q.push(root);
    out_graph = new GraphNode(root->uid);
    out_graph->val = root->val;

    node_map[root] = out_graph;

    while(!node_q.empty())
    {
        cur_node = node_q.front();
        node_q.pop();
        // visit all the neighbours of this node
        std::vector<GraphNode*> adj = cur_node->neighbours;

        for(unsigned int i = 0; i < adj.size(); ++i)
        {
            // check if we have created this node already
            if(node_map[adj[i]] == nullptr)
            {
                // create a new node
                out_graph = new GraphNode(adj[i]->uid);
                out_graph->val = adj[i]->val;
                node_map[adj[i]] = out_graph;
                node_q.push(adj[i]);
            }

            // Add neighbours for this node to the 
            // output graph node.
            node_map[cur_node]->neighbours.push_back(
                    node_map[adj[i]]
            );
        }
    }

    return node_map[root];
}

/*
 * graphSize()
 */
int graphSize(const GraphNode* root)
{
    int n = 0;
    const GraphNode* cur_node;
    std::unordered_set<const GraphNode*> visited;
    std::queue<const GraphNode*> bfs_q;

    if(root == nullptr)
        return n;

    bfs_q.push(root);

    while(!bfs_q.empty())
    {
        cur_node = bfs_q.front();
        bfs_q.pop();

        // add to visited list
        if(visited.count(cur_node) == 0)
        {
            visited.insert(cur_node);
            n++;
        }

        // Now check all the neighbours of this node
        for(unsigned int n = 0; n < cur_node->neighbours.size(); ++n)
        {
            if(visited.count(cur_node->neighbours[n]) == 0)
            {
                bfs_q.push(cur_node->neighbours[n]);
            }
        }
    }
    
    return n;
}

// TODO : implement this
bool hasCycle(const GraphNode* graph)
{
    const GraphNode* cur_node;
    std::unordered_set<const GraphNode*> visited;
}


/*
 * cloneGraph()
 */
Graph* cloneGraph(const Graph& graph)
{
    Graph* out_graph;

    return out_graph;
}



// ======== TRAVERSALS ======== //
// BFS

/*
 * graph_node_bfs()
 */
void graph_node_bfs(GraphNode* root, std::vector<int>& traversal)
{
    GraphNode* cur_node;
    std::queue<GraphNode*>  node_q;
    std::unordered_set<int> visited;        // hold uids of visited nodes

    node_q.push(root);

    while(!node_q.empty())
    {
        cur_node = node_q.front();
        node_q.pop();

        // add to visited list
        if(visited.count(cur_node->uid) == 0)
            visited.insert(cur_node->uid);

        traversal.push_back(cur_node->uid);

        // Now check all the neighbours of this node
        for(unsigned int n = 0; n < cur_node->neighbours.size(); ++n)
        {
            if(visited.count(cur_node->neighbours[n]->uid) == 0)
            {
                std::cout << "[" << __func__ << "] adding node " << cur_node->neighbours[n]->toString()
                    << " with uid [" << cur_node->neighbours[n]->uid << "]" << std::endl;
                node_q.push(cur_node->neighbours[n]);
                visited.insert(cur_node->neighbours[n]->uid);
            }
        }
    }
}

/*
 * graph_dfs_visit_q()
 */
void graph_dfs_visit_q(const GraphNode* root, std::vector<int>& traversal)
{
    std::cout << "[" << __func__ << "] AH HA HA HA HA! No Queue DFS in this commit!" << std::endl;
}

// DFS
void graph_node_dfs_inner(GraphNode* root, std::vector<int>& traversal, std::unordered_set<GraphNode*>& visited)
{
    visited.insert(root);
    traversal.push_back(root->uid);

    for(unsigned int n = 0; n < root->neighbours.size(); ++n)
    {
        if(visited.count(root->neighbours[n]) == 0)
        {
            graph_node_dfs_inner(root->neighbours[n], traversal, visited);
        }
    }
}
/*
 * graph_node_dfs()
 */
void graph_node_dfs(GraphNode* root, std::vector<int>& traversal)
{
    std::unordered_set<GraphNode*> visited;

    if(root != nullptr)
    {
        graph_node_dfs_inner(root, traversal, visited);
    }
}

// Compare two graphs
bool graph_node_equal(GraphNode* a, GraphNode* b)
{
    std::vector<int> traversal_a;
    std::vector<int> traversal_b;

    // BFS on each of the graphs
    graph_node_bfs(a, traversal_a);
    graph_node_bfs(b, traversal_b);

    // Compare the two traversals
    if(traversal_a.size() != traversal_b.size())
        return false;

    for(unsigned int n = 0; n < traversal_a.size(); ++n)
    {
        if(traversal_a[n] != traversal_b[n])
            return false;
    }

    return true;
}


// ======== ADJACENCY MATRIX ======== ///
AdjMatrix::AdjMatrix(unsigned int v) : dim(v), adj_matrix(v+1, std::vector<int>(v+1, 0)) {} 

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

/*
 * addEdge()
 */
void AdjList::addEdge(const std::vector<GraphEdge>& edges)
{
    // TODO: we don't check here for any conflict with existing edges..
    // That would require us to actually traverse the graph though, so 
    // leave it for now.
    this->adj_list.push_back(edges);
}


/*
 * toString()
 */
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


unsigned int AdjList::numVerticies(void) const
{
    return this->adj_list.size();
}
// TODO : num edges for directed and undirected graphs




// ======== ADJ_LIST_BFS ======== //
void adj_list_bfs(AdjList& list, std::vector<int>& traversal)
{
    std::cout << "[" << __func__ << "] TODO!" << std::endl;
}
