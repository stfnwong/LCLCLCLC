/*
 * HEAP2
 * This is just a copy of the Python Heap2 class.
 * Eventually this will be destroyed and folded into
 * the actual heap class.
 *
 * Stefan Wong 2020
 */

#include "heap2.hpp"


// Test if a vector has the min heap property
bool vector_is_min_heap(const std::vector<int>& vec, unsigned int idx)
{
    if(idx >= vec.size())
        return true;

    unsigned int lval, rval;

    lval = heap_left_child(idx);
    rval = heap_right_child(idx);

    if(lval >= vec.size() || rval >= vec.size())
        return true;
    
    if((vec[lval] <= vec[idx]) && (vec[rval] <= vec[idx]))
        return vector_is_min_heap(vec, idx+1);
    
    return false;
}

// Test if a vector has the max heap property
bool vector_is_max_heap(const std::vector<int>& vec, unsigned int idx)
{
    if(idx >= vec.size())
        return true;

    unsigned int lval, rval;

    lval = heap_left_child(idx);
    rval = heap_right_child(idx);

    // bounds check children
    if(lval >= vec.size() || rval >= vec.size())
        return true;

    if((vec[lval] >= vec[idx]) && (vec[rval] >= vec[idx]))
        return vector_is_min_heap(vec, idx+1);
    
    return false;
}


// ======== HEAP2 base class ======== //
Heap2::Heap2() {}

// Heap comparison, for now make it a min heap 
bool Heap2::compare(int a, int b) const
{
    return a >= b;
}

// TODO : there might be a fast way to do this
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
 * heapify_up()
 */
void Heap2::heapify_up(int idx)
{
    unsigned int child_idx;
    unsigned int parent_idx;
   
    child_idx = idx;
    while(child_idx > 0)
    {
        parent_idx = heap_parent(child_idx);
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
        parent_idx = heap_parent(idx);
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
