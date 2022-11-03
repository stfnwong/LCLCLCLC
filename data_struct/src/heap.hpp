/*
 * Heap implementations
 */


#ifndef __LC_HEAP_HPP
#define __LC_HEAP_HPP


#include <algorithm>
#include <stack>
#include <vector>

// Functions to index into max heaps when represented as arrays
unsigned max_heap_parent(unsigned idx);
unsigned max_heap_left(unsigned idx);
unsigned max_heap_right(unsigned idx);

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
        HeapNode(const T& val);
        ~HeapNode();
};


template <typename T> HeapNode<T>::HeapNode(const T& val) : val(val), left(nullptr), right(nullptr) {}

template <typename T> HeapNode<T>::~HeapNode()
{
    delete this->left;
    delete this->right;
}


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


template <typename T> bool node_is_max_heap(const HeapNode<T>& root, const std::stack<HeapNode<T>>& node_stack)
{
    // Base case: if there are no children then nothing to do
    if(root->left == nullptr && root->right == nullptr)
        return true;

    // Check child nodes
    if(root->left != nullptr)
    {
        // For max heap, this node must be greater or equal left node
        if(root->left->val > root->val)
            return false;

        if(root->right != nullptr)
        {
            // For max heap right must be less than or equal to left
            if(root->right->val > root->left->val)
                return false;
            node_stack.push(root->right);
        }

        node_stack.push(root->left);
    }

    if(!node_stack.empty())
        return node_is_max_heap(node_stack.pop(), node_stack);
}


/*
 *  HEAPARRAY
 *  This is an array based implementation of a heap.
 */
template <typename T> struct HeapArray
{
    std::vector<T> elements;

    public:
        HeapArray() {} 
        HeapArray(const std::vector<T>& heap_array)
        {
            this->elements = heap_array;
        }

        unsigned depth(void) const
        {
            unsigned d = 0;
            unsigned idx = 0;

            while(idx < this->elements.size())
            {
                // Descend down left side 
                unsigned l_dest = max_heap_left(idx);
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

};

// ======== MAX HEAPS USING ARRAYS ========= //
template <typename T> void max_heapify_array(std::vector<T>& items, unsigned idx)
{
    unsigned l = max_heap_left(idx);
    unsigned r = max_heap_right(idx);
    T largest;

    // Check which is largest of this and left 
    if((l < items.size()) && (items[l] > items[idx]))
        largest = l;
    else
        largest = idx;

    // Check which is largest of previous largest or right
    if((r < items.size()) && (items[r] > items[largest]))
        largest = r;

    if(largest != idx)
    {
        T temp = items[idx];
        items[largest] = items[idx];
        items[idx] = temp;
        max_heapify_array(items, largest);
    }
}




#endif  /*__LC_HEAP_HPP*/
