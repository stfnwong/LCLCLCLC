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
Heap::Heap() : nodes(std::vector<HeapNode>(100)), size(100) {}

Heap::Heap(const unsigned int max) : nodes(std::vector<HeapNode>(max)), size(max) {} 
    

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
            // TODO : check this...
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
    if((2*n) > this->size)
    {
        // do nothing
        return;
    }
    else if((2*n) < this->size)
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
 * insertNode()
 * Add the node to the end of the array and apply heapify up to it
 */
void Heap::insertNode(const HeapNode& node)
{
    this->nodes[this->size-1] = node;
    this->heapify_up(this->size-1);

    //if(this->nodes.size() < this->getSize())
    //{
    //    this->nodes[this->size-1] = node;
    //    this->heapify_up(this->size-1);
    //}
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
    return this->nodes[idx];
}

/*
 * getSize()
 */
unsigned int Heap::getSize(void) const
{
	return this->nodes.size();
}

/*
 * getMaxSize()
 */
unsigned int Heap::getMaxSize(void) const
{
    return this->size;
}


/*
 * getVector()
 */
std::vector<HeapNode> Heap::getVector(void) const
{
    return this->nodes;
}
