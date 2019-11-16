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

struct HeapNode
{
	int key;
	int val;

	public:
		HeapNode();
		HeapNode(int key, int val);

		void init(void);
		bool operator==(const HeapNode& that) const;
		bool operator!=(const HaapNode& that) const;
};


// Heap implemented with an array
// Because the internals are an array this heap has a fixed size
class Heap
{
	private:
		//std::vector<HeapNode> nodes;
		std::array <100, HeapNode> nodes;
		unsigned int size;


	private:
		heapify_up();
		heapify_down();

	public:
		Heap();
		Heap(unsigned int max);

		void addNode(const HeapNode& node);

		// getters 
		unsigned int getSize(void) const;
};


#endif /*__HEAP_HPP*/
