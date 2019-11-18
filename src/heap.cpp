/*
 * HEAP
 * Implementation of a heap
 *
 * Stefan Wong 2019
 */


#include <iostream>
#include "heap.hpp"



// ============== HEAP NODE ================ //

HeapNode::HeapNode()
{
	this->init();
}

HeapNode::HeapNode(int key, int val)
{
	this->key = key;
	this->val = val;
}

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


// ============== HEAP ================ //
Heap::Heap()
{
    this->size = 100;
}

Heap::Heap(const unsigned int max) 
{
    this->size = max;
}
    

// ======== Internal balancing functions ======== //
void Heap::heapify_up(void) 
{

}

void Heap::heapify_down(void)
{

}

void Heap::addNode(const HeapNode& node)
{
    if(this->nodes.size() < this->size)
    {
        std::cout << "[" << __func__ << "] this is where nodes are added" << std::endl;
    }
}

unsigned int Heap::getSize(void) const
{
	return this->nodes.size();
}

unsigned int Heap::getMax(void) const
{
    return this->size;
}
