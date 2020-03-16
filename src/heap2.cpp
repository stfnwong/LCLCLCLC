/*
 * HEAP2
 * This is just a copy of the Python Heap2 class.
 * Eventually this will be destroyed and folded into
 * the actual heap class.
 *
 * Stefan Wong 2020
 */

#include <iomanip>
#include <sstream>

#include "heap2.hpp"

// NOTE: we assume zero-index arrays here
int heap_left_child2(int idx)
{
    return 2 * idx + 1;
}
int heap_right_child2(int idx)
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

    unsigned int lval, rval;

    lval = heap_left_child2(idx);
    rval = heap_right_child2(idx);

    if(lval >= vec.size() || rval >= vec.size())
        return true;
    
    if((vec[lval] <= vec[idx]) && (vec[rval] <= vec[idx]))
        return vector_is_min_heap2(vec, idx+1);
    
    return false;
}

// Test if a vector has the max heap property
bool vector_is_max_heap2(const std::vector<int>& vec, unsigned int idx)
{
    if(idx >= vec.size())
        return true;

    unsigned int lval, rval;

    lval = heap_left_child2(idx);
    rval = heap_right_child2(idx);

    // bounds check children
    if(lval >= vec.size() || rval >= vec.size())
        return true;

    if((vec[lval] >= vec[idx]) && (vec[rval] >= vec[idx]))
        return vector_is_min_heap2(vec, idx+1);
    
    return false;
}


// ======== HEAP2 base class ======== //
Heap2::Heap2() {}

// Heap comparison, for now make it a min heap. In future this should be 
// one of the few methods that might need to be specalized for child heap
// types. TODO : Make Heap2 an abstract base class?
/*
 * compare()
 */
bool Heap2::compare(int a, int b) const
{
    return a >= b;
}

/*
 * swap()
 */
void Heap2::swap(int idx_a, int idx_b)
{
    std::iter_swap(this->heap.begin() + idx_a, this->heap.begin() + idx_b);
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


    return oss.str();
}

std::vector<int> Heap2::getVec(void) const
{
    return this->heap;
}


/*
 * heapify_up()
 */
void Heap2::heapify_up(int idx)
{
    unsigned int child_idx;
    unsigned int parent_idx;
   
    child_idx = idx;
    while(child_idx > 0)
    {
        parent_idx = heap_parent2(child_idx);
        if(this->compare(this->heap[parent_idx], this->heap[child_idx]))
            return;
        this->swap(parent_idx, child_idx);
        child_idx = parent_idx;
    }
}

/*
 * heapify_down()
 */
void Heap2::heapify_down(int idx)
{
    unsigned int child_idx;
    unsigned int parent_idx;

    child_idx = idx;
    while(child_idx > 0)
    {
        parent_idx = heap_parent2(child_idx);
        while(parent_idx < this->heap.size())
        {
            if(child_idx >= this->heap.size())
                return;

            // Do compare
            if((child_idx + 1 < this->heap.size()) && 
                    this->compare(child_idx + 1, child_idx))
                child_idx++;

            if(this->compare(this->heap[parent_idx], this->heap[child_idx]))
                return;

            //this->swap(this->heap[parent_idx], this->heap[child_idx]);
            this->swap(parent_idx, child_idx);
            parent_idx = child_idx;
        }
    }
}
