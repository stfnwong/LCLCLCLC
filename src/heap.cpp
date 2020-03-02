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

bool HeapNode::operator<(const HeapNode& that) const
{
    return (this->key < that.key) ? true : false;
}

bool HeapNode::operator<=(const HeapNode& that) const
{
    return (this->key <= that.key) ? true : false;
}

bool HeapNode::operator>(const HeapNode& that) const
{
    return (this->key > that.key) ? true : false;
}

bool HeapNode::operator>=(const HeapNode& that) const
{
    return (this->key >= that.key) ? true : false;
}

std::string HeapNode::toString(void) const
{
    std::ostringstream oss;

    oss << "[" << this->key << "]->" << this->val;

    return oss.str();
}


// ============== HEAP ================ //
Heap::Heap() : nodes(std::vector<HeapNode>(100)), max_size(100), num_elem(0) {}

Heap::Heap(const unsigned int max) : nodes(std::vector<HeapNode>(max)), max_size(max), num_elem(0) {} 
    

// ======== Internal balancing functions ======== //

/*
 * heapify_down()
 * TODO: this style sucks, and also I'm pretty sure this implementation
 * is not correct.
 */
//void Heap::heapify_down(unsigned int n)
//{
//    unsigned int j;
//    if((2*n) > this->max_size)
//    {
//        // do nothing
//        return;
//    }
//    else if((2*n) < this->max_size)
//    {
//        unsigned int left  = this->left_child(n);
//        unsigned int right = this->right_child(n);
//
//        std::cout << "[" << __func__ << "] node " << n 
//            << " left child is at " << left << ", right child is at " 
//            << right << std::endl;
//
//        if(this->nodes[left].key < this->nodes[right].key)
//            j = left;
//        else
//            j = right;
//    }
//    else        // 2*n == this->size
//    {
//        j = 2 * n;
//    }
//
//    if(this->nodes[j].key < this->nodes[n].key)
//    {
//        std::swap(this->nodes[j], this->nodes[n]);
//        this->heapify_down(j);
//    }
//}

/*
 * insertNode()
 * Add the node to the end of the array and apply heapify up to it
 * recursively to form an array that satisfies the heap property
 */
void Heap::insertNode(const HeapNode& node)
{
    if(this->num_elem < this->max_size)
    {
        this->nodes[this->num_elem] = node;
        this->heapify_up(num_elem);
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
 * Should be O(2 * log n)
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


// ======== Specializations 

// ==== MinHeap
MinHeap::MinHeap() : Heap() {} 

MinHeap::MinHeap(const unsigned int max) :  Heap(max) {} 

/*
 * MinHeap::heapify_up()
 */
void MinHeap::heapify_up(unsigned int idx)
{
    unsigned int p_idx; 

    p_idx = heap_parent(idx);
    // MinHeap : parents must be less than children
    if(this->nodes[p_idx] > this->nodes[idx])
    {
        std::swap(this->nodes[idx], this->nodes[p_idx]);
        this->heapify_up(p_idx);
    }
}

/*
 * MinHeap::heapify_down()
 */
void MinHeap::heapify_down(unsigned int idx) {} 


// ==== MinHeap
MaxHeap::MaxHeap() : Heap() {} 

MaxHeap::MaxHeap(const unsigned int max) : Heap(max) {} 

/*
 * MaxHeap::heapify_up()
 */
void MaxHeap::heapify_up(unsigned int idx)
{
    unsigned int p_idx; 

    p_idx = heap_parent(idx);
    // MaxHeap : parents must be greater than children
    if(this->nodes[p_idx] > this->nodes[idx])
    {
        std::swap(this->nodes[idx], this->nodes[p_idx]);
        this->heapify_up(p_idx);
    }
}

/*
 * MaxHeap::heapify_down()
 */
void MaxHeap::heapify_down(unsigned int idx) {} 



// ============== Heap utilities ================ //
unsigned int heap_parent(unsigned int idx)
{
    return (unsigned int) (idx <= 1) ? 0 : (idx >> 1);
}

unsigned int heap_left_child_idx(unsigned int idx)
{
    return 2 * (idx + 1) - 1;   // -1 here to account for zero index
}

unsigned int heap_right_child_idx(unsigned int idx)
{
    return 2 * (idx + 1);
}

bool has_min_heap_property(const Heap& heap)
{
    return array_has_min_heap_property(heap.getVector(), 0);
}

bool has_max_heap_property(const Heap& heap)
{
    return array_has_max_heap_property(heap.getVector(), 0);
}

/*
 * array_has_min_heap_property()
 */
bool array_has_min_heap_property(const std::vector<HeapNode>& nodes, unsigned int idx)
{
    unsigned int lidx, ridx;

    if(idx >= nodes.size()-1)
        return true;

    lidx = heap_left_child_idx(idx);
    ridx = heap_right_child_idx(idx);

    // If we get to the end and we've satisfied the heap property, then
    // this must be a heap.
    if((lidx >= nodes.size()-1) || (ridx >= nodes.size()-1)) 
        return true;

    if((nodes[lidx] <= nodes[idx]) && (nodes[ridx] <= nodes[idx]))
    {
        return array_has_min_heap_property(nodes, idx+1);
    }
    else
        return false;
}


/*
 * array_has_max_heap_property()
 */
bool array_has_max_heap_property(const std::vector<HeapNode>& nodes, unsigned int idx)
{
    unsigned int lidx, ridx;

    if(idx >= nodes.size()-1)
        return true;

    lidx = heap_left_child_idx(idx);
    ridx = heap_right_child_idx(idx);

    // If we get to the end and we've satisfied the heap property, then
    // this must be a heap.
    if((lidx >= nodes.size()-1) || (ridx >= nodes.size()-1)) 
        return true;

    if((nodes[lidx] >= nodes[idx]) && (nodes[ridx] >= nodes[idx]))
    {
        return array_has_max_heap_property(nodes, idx+1);
    }
    else
        return false;
}

