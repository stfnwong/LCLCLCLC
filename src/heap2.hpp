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
#include <vector>


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
bool vector_is_min_heap(const std::vector<int>& vec);

// Test if a vector has the max heap property
bool vector_is_max_heap(const std::vector<int>& vec);



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
        void heapify_up(int idx);
        void heapify_down(int idx);

    public:
        Heap2();

        // setters 
        void         insert(int val);

        // getters
        unsigned int size(void) const;
        int          getRoot(void) const;
        int          getMin(void) const;
        int          getMax(void) const;
        // functions that modify heap
        //int          popMin(void);
        //int          popMax(void);
};


//class MinHeap2 : public Heap2
//{
//
//};



#endif /*__LC_HEAP2_HPP*/
