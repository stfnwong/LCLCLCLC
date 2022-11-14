/*
 * Heap implementations
 */


#ifndef __LC_HEAP_HPP
#define __LC_HEAP_HPP

// TODO: debug only, remove
#include <iostream>
#include "util.hpp"

#include <algorithm>
#include <queue>
#include <functional>
#include <stack>
#include <vector>

// Functions to index into max heaps when represented as arrays
unsigned heap_parent(unsigned idx);
unsigned heap_left_child(unsigned idx);
unsigned heap_right_child(unsigned idx);

/*
 *  HEAPNODE
 *  This is a Node-based heap implementation with raw pointers
 */
template <typename T> struct HeapNode
{
    T val;
    HeapNode<T>* left;
    HeapNode<T>* right;

    public:
        HeapNode(const T& val) : val(val) {}
        ~HeapNode() 
        {
            delete this->left;
            delete this->right;
        }
};



// ======== MAX HEAPS USING NODES ========= //
//template <typename T> HeapNode<T> create_heap(const std::vector<T>& items)
//{
//    return HeapNode<T>(0);
//}
//
//template <typename T> void max_heapify(std::vector<T>& items)
//{
//}
//
//template <typename T> HeapNode<T> max_heap_array_to_node(const std::vector<T>& items)
//{
//}
//







/*
 *  HEAPARRAY
 *  This is an array based implementation of a heap.
 */
template <typename T, class Compare = std::less<T>> struct HeapArray
{
    private:
        std::vector<T> elements;

    protected:
        Compare comp;        // a comparison function
        unsigned left_child(unsigned idx) const {
            return 2 * idx + 1;
        }
        unsigned right_child(unsigned idx) const {
            return 2 * idx + 2;
        }

    public:
        HeapArray(const Compare& comp = Compare()) : comp(comp) {} 
        HeapArray(const std::vector<T>& heap_array, const Compare& comp = Compare()) 
            : elements(heap_array), comp(comp)
        {
            //this->heapify_up(this->elements.size()-1);
            for(unsigned idx = (this->elements.size() / 2); idx > 0; --idx)
            {
                this->heapify_down(idx);
            }
        }

        /*
         * Test that this heap has the "required" heap property. The required heap 
         * property is the one that would satisfy the comparison function
         */
        bool has_heap_property(unsigned idx) const
        {
            if(idx >= this->elements())
                return true;

            unsigned left = this->left_child(idx);
            unsigned right = this->right_child(idx);

            // we go over the edge of the array then we consider its a 
            if(left > this->elements.size() || right > this->elements.size())
                return true;
            
            if(this->comp(this->elements[left], this->elements[idx]) &&
               this->comp(this->elements[right], this->elements[idx]))
                this->has_heap_property(idx+1);

            return false;
        }

        unsigned depth(void) const
        {
            unsigned d = 0;
            unsigned idx = 0;

            while(idx < this->elements.size())
            {
                // Descend down left side 
                unsigned l_dest = this->left_child(idx);
                if(l_dest < this->elements.size())
                {
                    d++;
                    idx = l_dest;
                }
            }

            return d;
        }

        unsigned size(void) const
        {
            return this->elements.size();
        }

        void insert(const T& item)
        {
            this->elements.push_back(item);
            this->heapify_up(this->elements.size());
        }

        /*
         * Starting from the top, ensure the heap property holds for all nodes in 
         * the array.
         */
        void heapify_down(unsigned idx)
        {
            unsigned left = this->left_child(idx);
            unsigned right = this->right_child(idx);
            unsigned swap_idx = idx;          // TODO: need a better name, but this is the element that gets swapped when 

            // check left child 
            if(left < this->elements.size() && 
                    (this->comp(this->elements[left], this->elements[idx]))
              )
                swap_idx = left;

            // check the other index 
            if(right < this->elements.size() && 
                        (this->comp(this->elements[right], this->elements[swap_idx]))
              )
                swap_idx = right;

            if(swap_idx != idx)
            {
                // time to swap
                std::swap(this->elements[idx], this->elements[swap_idx]);
                this->heapify_down(swap_idx);
            }
        }
        /*
         * Starting from the bottom, ensure the heap property holds for all nodes in
         * the array.
         */

        void heapify_up(const int i)
        {
        }

};

// ======== HEAPS USING ARRAYS ========= //

template <typename T> bool is_max_heap(const std::vector<T>& array)
{
    // do a level order traversal on the array and test each pair 
    std::queue<unsigned> idx_q;

    unsigned left, right;

    idx_q.push(0);

    while(!idx_q.empty())
    {
        unsigned num_nodes = idx_q.size();
        for(unsigned i = 0; i < num_nodes; ++i)
        {
            unsigned cur_idx = idx_q.front();
            idx_q.pop();

            left = heap_left_child(cur_idx);
            right = heap_right_child(cur_idx);

            // if we are at a leaf, assume we have the heap property and continue
            if(left >= array.size() && right >= array.size())
                continue;

            if(left < array.size())
            {
                if(array[left] > array[cur_idx])
                    return false;
                idx_q.push(left);
            }
            if(right < array.size())
            {
                if(array[right] > array[cur_idx])
                    return false;
                idx_q.push(right);
            }
        }
    }

    return true;
}


template <typename T> bool is_min_heap(const std::vector<T>& array)
{
    std::queue<unsigned> idx_q;
}



/*
 * Max heapify an array
 */
template <typename T> void max_heapify_array(std::vector<T>& items, unsigned i)
{
    unsigned l = heap_left_child(i);
    unsigned r = heap_right_child(i);
    unsigned largest;

    // Check which is largest of this and left 
    if((l < items.size()) && (items[l] > items[i]))
        largest = l;
    else
        largest = i;

    // Check which is largest of previous largest or right
    if((r < items.size()) && (items[r] > items[largest]))
        largest = r;

    std::cout << vec_to_str(items) << std::endl;

    std::cout << "[" << __func__ << "] largest [" << largest << "], i [" 
        << i << "], items[largest]: " << items[largest] << ", items[l]: " 
        << items[l] << ", items[r]: " << items[r] << "" << std::endl;

    if(largest != i)
    {
        T temp = items[largest];
        items[largest] = items[i];
        items[i] = temp;
        max_heapify_array(items, largest);
    }
}


/*
 * Min heapify an array
 */
template <typename T> void min_heapify_array(std::vector<T>& items, unsigned i)
{
    unsigned l = heap_left_child(i);
    unsigned r = heap_right_child(i);
    unsigned smallest;
    
    if((l < items.size()) && (items[l] < items[i]))
        smallest = l;
    else
        smallest = i;
    if((r < items.size()) && (items[r] < items[smallest]))
        smallest = r;

    // TODO: std::swap() here...
    if(smallest != i)
    {
        T temp = items[smallest];
        items[smallest] = items[i];
        items[i] = temp;
        min_heapify_array(items, smallest);
    }
}


/*
 * Build a max heap from an array
 */
template <typename T> void build_max_heap_array(std::vector<T>& items)
{
    unsigned heap_size = items.size();
    for(unsigned idx = (heap_size / 2)-1; idx >= 0; --idx)
    {
        max_heapify_array(items, idx);
    }
}



#endif  /*__LC_HEAP_HPP*/
