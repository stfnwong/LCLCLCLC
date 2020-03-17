/*
 * HEAP2
 * This is just a copy of the Python Heap class.
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
bool vector_is_min_heap(const std::vector<int>& vec, unsigned int idx);
// Test if a vector has the max heap property
bool vector_is_max_heap(const std::vector<int>& vec, unsigned int idx);

/*
 * Heap 
 * New (simpler) heap implementation to get logic correct.
 */
class Heap
{
    protected:
        std::vector<int> heap;

    // internal manipulation
    protected:
        virtual bool compare(int a, int b) const = 0;
        void swap(int idx_a, int idx_b);

    // Update heap
    protected:
        void heapify(int idx);

    public:
        Heap();
        Heap(const Heap& that);
        Heap(const Heap&& that);

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


/*
 * MinHeap
 * Implements a min heap
 */
class MinHeap : public Heap
{
    protected:
        bool compare(int parent, int child) const;

    // TODO : what about ctors?
};

class MaxHeap : public Heap
{
    protected:
        bool compare(int parent, int child) const;
};

#endif /*__LC_HEAP2_HPP*/
