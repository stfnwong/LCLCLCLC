/*
 * HEAP
 * Implementation of a heap
 *
 * Stefan Wong 2019
 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include "heap.hpp"


// ============== HEAP NODE ================ //

HeapNode::HeapNode()
{
	this->init();
}

HeapNode::HeapNode(int key)
{
    this->key = key;
    this->val = 0;
}

HeapNode::HeapNode(int key, int val)
{
	this->key = key;
	this->val = val;
}

// copy ctor
HeapNode::HeapNode(const HeapNode& that)
{
    this->key = that.key;
    this->val = that.val;
}

// move ctor
//HeapNode::HeapNode(HeapNode&& that)
//{
//
//}

void HeapNode::init(void)
{
	this->key = 0;
	this->val = 0;
}

bool HeapNode::operator==(const HeapNode& that) const
{
	if(this->key != that.key)
		return false;
	if(this->val != that.val)
		return false;

	return true;
}

bool HeapNode::operator!=(const HeapNode& that) const
{
	return !(*this == that);
}

std::string HeapNode::toString(void) const
{
    std::ostringstream oss;

    oss << "[" << this->key << "] : " << this->val;

    return oss.str();
}


// ============== HEAP ================ //
Heap::Heap() : nodes(std::vector<HeapNode>(100)), max_size(100), num_elem(0) {}

Heap::Heap(const unsigned int max) : nodes(std::vector<HeapNode>(max)), max_size(max), num_elem(0) {} 
    

// ======== Internal balancing functions ======== //

/*
 * parent()
 * Find the parent of node n. In this case, the parent is just the 
 * node that is in the other half of the array
 */
unsigned int Heap::parent(unsigned int n)
{
    return (n >> 1);
}

/*
 * heapify_up()
 */
void Heap::heapify_up(unsigned int n) 
{
    if(n > 1)
    {
        unsigned int j = this->parent(n);
        if(this->nodes[n].key < this->nodes[j].key)
        {
            // TODO : This swap is causing an element with a zero key
            // to appear in the output vector
            std::swap(this->nodes[n], this->nodes[j]);
            this->heapify_up(j);
        }
    }
}

/*
 * heapify_down()
 */
void Heap::heapify_down(unsigned int n)
{
    unsigned int j;
    if((2*n) > this->max_size)
    {
        // do nothing
        return;
    }
    else if((2*n) < this->max_size)
    {
        int left  = 2 * n;
        int right = 2 *n + 1;

        if(this->nodes[left].key < this->nodes[right].key)
            j = left;
        else
            j = right;
    }
    else        // 2*n == this->size
    {
        j = 2 * n;
    }

    if(this->nodes[j].key < this->nodes[n].key)
    {
        std::swap(this->nodes[j], this->nodes[n]);
        this->heapify_down(j);
    }
}

/*
 * left_child()
 */
unsigned int Heap::left_child(unsigned int n)
{
    return (2 * n) * 2 - 1;
}

/*
 * right_child()
 */
unsigned int Heap::right_child(unsigned int n)
{
    return (2 * n) * 2;
}


/*
 * insertNode()
 * Add the node to the end of the array and apply heapify up to it
 */
void Heap::insertNode(const HeapNode& node)
{
    if(this->num_elem < this->max_size)
    {
        int next_pos = this->num_elem + 1;
        this->nodes[next_pos] = node;
        this->heapify_up(next_pos);
        this->num_elem++;
    }
}

/*
 * deleteNode()
 */
void Heap::deleteNode(unsigned int idx)
{
    std::cout << "[" << __func__ << "] not yet implemented" << std::endl;
}

/*
 * remove()
 */
HeapNode Heap::remove(unsigned int idx)
{
    this->num_elem--;
    return this->nodes[this->num_elem+1];
}

/*
 * getNumElem()
 */
unsigned int Heap::getNumElem(void) const
{
	//return this->nodes.size();
    return this->num_elem;
}

/*
 * getMaxSize()
 */
unsigned int Heap::getMaxSize(void) const
{
    return this->max_size;
}


/*
 * getVector()
 */
std::vector<HeapNode> Heap::getVector(void) const
{
    return this->nodes;
}
