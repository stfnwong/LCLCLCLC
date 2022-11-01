/*
 * Heap implementations 
 */


#ifndef __LC_HEAP_HPP
#define __LC_HEAP_HPP



/*
 *  HEAPNODE
 *  This is a Node-based heap implementation with raw pointers 
 */


template <typename T> struct HeapNode 
{
    T elem;
    HeapNode<T>* left;
    HeapNode<T>* right;

    public:
        HeapNode(const T& val);
        ~HeapNode();
};


template <typename T> HeapNode<T>::HeapNode(const T& val) : elem(val), left(nullptr), right(nullptr) {}

template <typename T> HeapNode<T>::~HeapNode()
{
    delete this->left;
    delete this->right;
}




#endif  /*__LC_HEAP_HPP*/
