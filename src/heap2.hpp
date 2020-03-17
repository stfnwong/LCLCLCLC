/*
 * HEAP2
 * This is just a copy of the Python Heap2 class.
 * Eventually this will be destroyed and folded into
 * the actual heap class.
 *
 * Stefan Wong 2020
 */

#ifndef __LC_HEAP2_HPP
#define __LC_HEAP2_HPP

#include <algorithm>
#include <string>
#include <vector>

// TODO : namespacing ?

// Test if a vector has the min heap property
bool vector_is_min_heap2(const std::vector<int>& vec, unsigned int idx);
// Test if a vector has the max heap property
bool vector_is_max_heap2(const std::vector<int>& vec, unsigned int idx);

/*
 * Heap2 
 * New (simpler) heap implementation to get logic correct.
 */
class Heap2
{
    protected:
        std::vector<int> heap;

    // internal manipulation
    protected:
        bool compare(int a, int b) const;
        void swap(int idx_a, int idx_b);

    // Update heap
    protected:
        void max_heapify(int idx);
        void min_heapify(int idx);
        //void build_min_heap(const std::vector<int>& arr);
        // NOTE : this is the alternative construction where we
        // always insert at the bottom leftmost position and then
        // bubble up if needed 
        void up_heap_min(int idx);

    public:
        Heap2();
        Heap2(const Heap2& that);
        Heap2(const Heap2&& that);

        // setters 
        void         insert(int val);
        // getters
        unsigned int size(void) const;
        int          getRoot(void) const;
        int          getMin(void) const;
        int          getMax(void) const;
        bool         empty(void) const;
        std::string  toString(void) const;
        std::vector<int> getVec(void) const;    // TODO : this is bad API design, but leave it for now until internal implementation is sorted
        // functions that modify heap
        //int          popMin(void);
        //int          popMax(void);

        // TODO : some way to print the heap?
};


//class MinHeap2 : public Heap2
//{
//
//};

#endif /*__LC_HEAP2_HPP*/
