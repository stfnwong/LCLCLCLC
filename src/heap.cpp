/*
 * HEAP2
 * This is just a copy of the Python Heap2 class.
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
bool vector_is_min_heap2(const std::vector<int>& vec, unsigned int idx)
{
    if(idx >= vec.size())
        return true;

    unsigned int lchild, rchild;

    lchild = heap2_left_child(idx);
    rchild = heap2_right_child(idx);

    std::cout << "[" << __func__ << "] (indicies) idx: " << idx 
        << ", lchild: " << lchild << ", rchild: " << rchild 
        << std::endl;
    std::cout << "[" << __func__ << "] values : ";
    std::cout << "heap[" << idx << "] = " << vec[idx]
        << ",  ";
    std::cout << "heap[" << lchild << "] = " << vec[lchild]
        << ",  ";
    std::cout << "heap[" << rchild << "] = " << vec[rchild]
        << " ";
    std::cout << std::endl;

    // bounds check children
    if(lchild >= vec.size() || rchild >= vec.size())
        return true;
    
    if((vec[lchild] >= vec[idx]) && (vec[rchild] >= vec[idx]))
        return vector_is_min_heap2(vec, idx+1);
    
    return false;
}

// Test if a vector has the max heap property
bool vector_is_max_heap2(const std::vector<int>& vec, unsigned int idx)
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
        return vector_is_max_heap2(vec, idx+1);
    
    return false;
}


// ======== HEAP2 base class ======== //
Heap2::Heap2() {}

// copy ctor
Heap2::Heap2(const Heap2& that) 
{
    this->heap = that.heap;     
}

// move ctor
Heap2::Heap2(const Heap2&& that) 
{
    this->heap = std::move(that.heap);
    // how to I invalidate the src structure?
}


// Heap comparison, for now make it a min heap. In future this should be 
// one of the few methods that might need to be specalized for child heap
// types. TODO : Make Heap2 an abstract base class?
/*
 * compare()
 */
bool Heap2::compare(int parent, int child) const
{
    return parent > child;
}

/*
 * swap()
 */
void Heap2::swap(int idx_a, int idx_b)
{
    //std::iter_swap(this->heap.begin() + idx_a, this->heap.begin() + idx_b);
    // FIXME : crap swap
    int a_val = this->heap[idx_a];
    int b_val = this->heap[idx_b];

    std::cout << "[" << __func__ << "] swapping heap[" << idx_a 
        << "] = " << this->heap[idx_a] << " with heap[" << idx_b
        << "] = " << this->heap[idx_b] << std::endl;

    this->heap[idx_a] = b_val;
    this->heap[idx_b] = a_val;
}

// INSERTION 
void Heap2::insert(int val)
{
    this->heap.push_back(val);
    this->heapify(this->heap.size() - 1);
    //this->min_heapify(this->heap.size() - 1);       // start from the bottom
    //this->min_heapify(0);   // start from the top
}

/*
 * size()
 */
unsigned int Heap2::size(void) const
{
    return this->heap.size();
}

/*
 * empty()
 */
bool Heap2::empty(void) const
{
    return (this->heap.size() == 0) ? true : false;
}

/*
 * toString()
 */
std::string Heap2::toString(void) const
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
std::vector<int> Heap2::getVec(void) const
{
    return this->heap;
}

/*
 * heapify()
 * TODO : we can put this->compare() here and generalize
 */
void Heap2::heapify(int idx)
{
    unsigned int parent_idx;

    // this must be smaller than the current idx
    parent_idx = heap_parent2(idx);
    
    // this node needs to be less than its parent
    if(this->compare(this->heap[parent_idx], this->heap[idx]))
    {
        this->swap(idx, parent_idx);
        this->heapify(parent_idx);  // check this nodes parent
    }
}


/*
 * MinHeap comparison
 */
bool MinHeap2::compare(int parent, int child)
{
    return parent > child;
}

/*
 * MaxHeap comparison
 */
bool MaxHeap2::compare(int parent, int child)
{
    return parent < child;
}


