/*
 * HEAP
 * Implementation of a heap
 *
 * Stefan Wong 2019
 */

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
Heap::Heap() : nodes(std::array<100, HeapNode>), size(100) {} 

Heap::Heap(unsigned int max) : nodes(std::array<max, HeapNode>), size(max) {} 


unsigned int Heap::getSize(void) const
{
	return this->nodes.size();
}
