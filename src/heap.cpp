/*
 * HEAP2
 * This is just a copy of the Python Heap class.
 * Eventually this will be destroyed and folded into
 * the actual heap class.
 *
 * Stefan Wong 2020
 */

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "heap.hpp"

// NOTE: we assume zero-index arrays here
int heap_left_child(int idx)
{
    return 2 * idx + 1;
}
int heap_right_child(int idx)
{
    return 2 * idx + 2;
}
int heap_parent(int idx)
{
    return std::max(0, idx / 2);
}

// Test if a vector has the min heap property
bool vector_is_min_heap(const std::vector<int>& vec, unsigned int idx)
{
    if(idx >= vec.size())
        return true;

    unsigned int lchild, rchild;

    lchild = heap_left_child(idx);
    rchild = heap_right_child(idx);

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

    lchild = heap_left_child(idx);
    rchild = heap_right_child(idx);

    // bounds check children
    if(lchild >= vec.size() || rchild >= vec.size())
        return true;

    if((vec[lchild] <= vec[idx]) && (vec[rchild] <= vec[idx]))
        return vector_is_max_heap(vec, idx+1);
    
    return false;
}



// ======== HEAP base class ======== //
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
    this->heapify_up(this->heap.size() - 1);
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

    oss << "<" << this->repr() << "> {";
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
 * isMinHeap()
 */
bool Heap::isMinHeap(void) const
{
    return vector_is_min_heap(this->heap, 0);
}

/*
 * isMaxHeap()
 */
bool Heap::isMaxHeap(void) const
{
    return vector_is_max_heap(this->heap, 0);
}


/*
 * heapify_up()
 */
void Heap::heapify_up(int idx)
{
    unsigned int parent_idx;

    // this must be smaller than the current idx
    parent_idx = heap_parent(idx);
    if(this->compare(this->heap[parent_idx], this->heap[idx]))
    {
        this->swap(idx, parent_idx);
        this->heapify_up(parent_idx);  // check this nodes parent
    }
}


// =============== MIN HEAP  =============== 

/*
 * repr()
 */
std::string MinHeap::repr(void) const
{
    return "MinHeap";
}

/*
 * MinHeap comparison
 */
bool MinHeap::compare(int parent, int child) const
{
    return parent > child;
}

/*
 * heapify_down()
 * Perform heapify operation from the root down
 */
void MinHeap::heapify_down(int idx)
{
    unsigned int lchild, rchild;
    unsigned int smallest_idx;

    lchild = heap_left_child(idx);
    rchild = heap_right_child(idx);

    if(lchild >= this->heap.size() || rchild >= this->heap.size())
        return;

    if(this->heap[lchild] < this->heap[idx])
        smallest_idx = lchild;
    else
        smallest_idx = idx;

    if(this->heap[rchild] < this->heap[smallest_idx])
        smallest_idx = rchild;

    if(smallest_idx != idx)
    {
        this->swap(smallest_idx, idx);
        this->heapify_down(smallest_idx);
    }
}

/*
 * get_max()
 */
int MinHeap::get_max(unsigned int idx) const
{
    int max_elem = this->heap[this->heap.size() / 2];
    unsigned int N = this->heap.size();

    for(unsigned int i = (N / 2); i < N; ++i)
        max_elem = std::max(this->heap[i], max_elem);

    return max_elem;
}

/*
 * getMin()
 */
int MinHeap::getMin(void) const
{
    return this->heap[0];
}

/*
 * getMin()
 */
int MinHeap::getMax(void) const
{
    return this->get_max(0); 
}

/*
 * popMin()
 */
int MinHeap::popMin(void)
{
    int min = this->heap[0];
    this->heap.front() = std::move(this->heap.back());
    this->heap.pop_back();
    // re-heapify
    this->heapify_down(0);

    return min;
}

// TODO : there should be scope for refactoring here...
/*
 * popMax()
 */
int MinHeap::popMax(void)
{
    int          max_elem = this->heap[(this->heap.size() - 1) / 2];
    unsigned int N        = this->heap.size();
    int          max_elem_idx = (this->heap.size() - 1) / 2;

    for(unsigned int i = (N/2); i < N; ++i)
    {
        if(this->heap[i] > max_elem)
        {
            max_elem = this->heap[i];
            max_elem_idx = i;
        }
    }

    this->heap[max_elem_idx] = std::move(this->heap.back());
    this->heap.pop_back();
    this->heapify_down(0);

    return max_elem;
}




// =============== MAX HEAP  ===============  //

std::string MaxHeap::repr(void) const
{
    return "MaxHeap";
}

/*
 * MaxHeap comparison
 */
bool MaxHeap::compare(int parent, int child) const
{
    return parent < child;
}

// NOTE: start at heap.size(), work backwards...
int MaxHeap::get_min(unsigned int idx) const
{
    int min_elem = this->heap[(this->heap.size() - 1) / 2];
    unsigned int N = this->heap.size();

    for(unsigned int i = (N / 2); i < N; ++i)
        min_elem = std::min(this->heap[i], min_elem);

    return min_elem;
}

/*
 * heapify_down()
 */
void MaxHeap::heapify_down(int idx) // TODO : unsigned int here
{
    unsigned int lchild, rchild;
    unsigned int largest_idx;

    lchild = heap_left_child(idx);
    rchild = heap_right_child(idx);

    if(lchild >= this->heap.size() || rchild >= this->heap.size())
        return;

    if(this->heap[lchild] > this->heap[idx])
        largest_idx = lchild;
    else
        largest_idx = idx;

    if(this->heap[rchild] > this->heap[largest_idx])
        largest_idx = rchild;

    if(largest_idx != idx)
    {
        this->swap(largest_idx, idx);
        this->heapify_down(largest_idx);
    }
}

/*
 * getMin()
 */
int MaxHeap::getMin(void) const
{
    return this->get_min(0);
}

/*
 * getMax()
 */
int MaxHeap::getMax(void) const
{
    return this->heap[0];
}

/*
 * popMin()
 */
int MaxHeap::popMin(void) 
{
    // lets just search over the bottom 'half' of the array
    int          min_elem = this->heap[(this->heap.size() - 1) / 2];
    unsigned int N        = this->heap.size();
    int          min_elem_idx = (this->heap.size() - 1) / 2;

    for(unsigned int i = (N/2); i < N; ++i)
    {
        if(this->heap[i] < min_elem)
        {
            min_elem = this->heap[i];
            min_elem_idx = i;
        }
    }

    this->heap[min_elem_idx] = std::move(this->heap.back());
    this->heap.pop_back();
    this->heapify_down(0);

    return min_elem;
}

/*
 * popMax()
 */
int MaxHeap::popMax(void)
{
    int root;

    root = this->heap[0];
    // max of max heap is root
    this->heap.front() = std::move(this->heap.back());
    this->heap.pop_back();
    this->heapify_down(0);  // NOTE: when do we ever not heapify from the root? 

    return root;
}

