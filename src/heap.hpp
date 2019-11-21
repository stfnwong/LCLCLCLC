/*
 * HEAP
 * Implementation of a heap
 *
 * Stefan Wong 2019
 */

#ifndef __HEAP_HPP
#define __HEAP_HPP

#include <array>
#include <vector>

// Single node in a heap
struct HeapNode
{
	int key;
	int val;

	public:
		HeapNode();
        HeapNode(int key);
		HeapNode(int key, int val);
        // copy ctor
        HeapNode(const HeapNode& that);
        // move ctor

		void init(void);
		bool operator==(const HeapNode& that) const;
		bool operator!=(const HeapNode& that) const;

        // Copy assignment?
        std::string toString(void) const;
};


// Heap implemented with an array
// Because the internals are an array this heap has a fixed size
// TODO: a version that is more flexible?
class Heap
{
	private:
		std::vector<HeapNode> nodes;
		unsigned int max_size;
        unsigned int num_elem;

	private:
        unsigned int parent(unsigned int n);
		void heapify_up(unsigned int n);
		void heapify_down(unsigned int n);

	public:
		Heap();
		Heap(const unsigned int max);

		void     insertNode(const HeapNode& node);
        void     deleteNode(unsigned int idx);
        HeapNode remove(unsigned int idx);

		// getters 
		unsigned int getNumElem(void) const;
        unsigned int getMaxSize(void) const;
        // More for debugging than anything...
        std::vector<HeapNode> getVector(void) const;
};


#endif /*__HEAP_HPP*/
