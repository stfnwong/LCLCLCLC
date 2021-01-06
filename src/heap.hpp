/*
 * HEAP2
 * This is just a copy of the Python Heap class.
 * Eventually this will be destroyed and folded into
 * the actual heap class.
 *
 * Stefan Wong 2020
 */

#ifndef __LC_HEAP_HPP
#define __LC_HEAP_HPP

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
        std::vector<int>    heap;

    // internal manipulation
    protected:
        virtual std::string repr(void) const = 0;
        virtual bool        compare(int a, int b) const = 0;
        void                swap(unsigned int idx_a, unsigned int idx_b);

    // Update heap
    protected:
        // Heapify from the root towards the leaf
        virtual void        heapify_down(unsigned int idx) = 0;
        // Heapify from the leaf towards the root 
        void                heapify_up(unsigned int idx);

    public:
        Heap();
        Heap(const Heap& that);
        Heap(const Heap&& that);

        // setters 
        void               insert(int val);
        // getters
        unsigned int       size(void) const;
        int                getRoot(void) const;
        bool               empty(void) const;
        std::string        toString(void) const;
        std::vector<int>   getVec(void) const;    

        bool               isMinHeap(void) const;
        bool               isMaxHeap(void) const;
        virtual int        popMin(void) = 0;
        virtual int        popMax(void) = 0;
        virtual int        getMin(void) const = 0;
        virtual int        getMax(void) const = 0;
        virtual int        pop(void) = 0;
};


/*
 * MinHeap
 * Implements a min heap
 */
class MinHeap : public Heap
{
    protected:
        std::string repr(void) const;
        bool        compare(int parent, int child) const;
        void        heapify_down(unsigned int idx);
        int         get_max(unsigned int idx) const;

    public:
        int         getMin(void) const;
        int         getMax(void) const;
        int         popMin(void);
        int         popMax(void);
        int         pop(void);
};

/*
 * MaxHeap
 * Implements a max heap
 */
class MaxHeap : public Heap
{
    protected:
        std::string repr(void) const;
        bool        compare(int parent, int child) const;
        void        heapify_down(unsigned int idx);
        int         get_min(unsigned int idx) const;

    public:
        int         getMin(void) const;
        int         getMax(void) const;
        int         popMin(void);
        int         popMax(void);
        int         pop(void);
};

#endif /*__LC_HEAP_HPP*/
