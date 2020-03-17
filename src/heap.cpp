/*
 * HEAP2
 * This is just a copy of the Python Heap class.
 * Eventually this will be destroyed and folded into
 * the actual heap class.
 *
 * Stefan Wong 2020
 */

#include <iomanip>
#include <iostream>
#include <sstream>

#include "heap.hpp"

// NOTE: we assume zero-index arrays here
int heap2_left_child(int idx)
{
    return 2 * idx + 1;
}
int heap2_right_child(int idx)
{
    return 2 * idx + 2;
}
int heap_parent2(int idx)
{
    return std::max(0, idx / 2);
}

// Test if a vector has the min heap property
bool vector_is_min_heap(const std::vector<int>& vec, unsigned int idx)
{
    if(idx >= vec.size())
        return true;

    unsigned int lchild, rchild;

    lchild = heap2_left_child(idx);
    rchild = heap2_right_child(idx);

    // bounds check children
    if(lchild >= vec.size() || rchild >= vec.size())
        return true;
    
    if((vec[lchild] >= vec[idx]) && (vec[rchild] >= vec[idx]))
        return vector_is_min_heap(vec, idx+1);
    
    return false;
}

// Test if a vector has the max heap property
bool vector_is_max_heap(const std::vector<int>& vec, unsigned int idx)
{
    if(idx >= vec.size())
        return true;

    unsigned int lchild, rchild;

    lchild = heap2_left_child(idx);
    rchild = heap2_right_child(idx);

    // bounds check children
    if(lchild >= vec.size() || rchild >= vec.size())
        return true;

    if((vec[lchild] <= vec[idx]) && (vec[rchild] <= vec[idx]))
        return vector_is_max_heap(vec, idx+1);
    
    return false;
}


// ======== HEAP2 base class ======== //
Heap::Heap() {}

// copy ctor
Heap::Heap(const Heap& that) 
{
    this->heap = that.heap;     
}

// move ctor
Heap::Heap(const Heap&& that) 
{
    this->heap = std::move(that.heap);
    // how to I invalidate the src structure?
}

/*
 * swap()
 */
void Heap::swap(int idx_a, int idx_b)
{
    std::iter_swap(this->heap.begin() + idx_a, this->heap.begin() + idx_b);
}

// INSERTION 
void Heap::insert(int val)
{
    this->heap.push_back(val);
    this->heapify(this->heap.size() - 1);
}

/*
 * size()
 */
unsigned int Heap::size(void) const
{
    return this->heap.size();
}

/*
 * empty()
 */
bool Heap::empty(void) const
{
    return (this->heap.size() == 0) ? true : false;
}

/*
 * toString()
 */
std::string Heap::toString(void) const
{
    std::ostringstream oss;

    // FIXME  : for now just print the vector contents
    oss << "{";
    for(unsigned int i = 0; i < this->heap.size(); ++i)
        oss << this->heap[i] << " ";
    oss << "}";

    return oss.str();
}

/*
 * getVec()
 */
std::vector<int> Heap::getVec(void) const
{
    return this->heap;
}

/*
 * heapify()
 */
void Heap::heapify(int idx)
{
    unsigned int parent_idx;

    // this must be smaller than the current idx
    parent_idx = heap_parent2(idx);
    
    if(this->compare(this->heap[parent_idx], this->heap[idx]))
    {
        this->swap(idx, parent_idx);
        this->heapify(parent_idx);  // check this nodes parent
    }
}

/*
 * MinHeap comparison
 */
bool MinHeap::compare(int parent, int child) const
{
    return parent > child;
}

/*
 * MaxHeap comparison
 */
bool MaxHeap::compare(int parent, int child) const
{
    return parent < child;
}
