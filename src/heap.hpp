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
        // move ctor?

		void init(void);
		bool operator==(const HeapNode& that) const;
		bool operator!=(const HeapNode& that) const;
        bool operator<(const HeapNode& that) const;
        bool operator<=(const HeapNode& that) const;
        bool operator>(const HeapNode& that) const;
        bool operator>=(const HeapNode& that) const;

        // Copy assignment?
        std::string toString(void) const;
};


// Heap implemented with an array
// Because the internals are an array this heap has a fixed size
// TODO: a version that is more flexible?
class Heap
{
	protected:
		std::vector<HeapNode> nodes;
		unsigned int max_size;          // TODO : what does this do?
        unsigned int num_elem;

	protected:
		virtual void heapify_up(unsigned int n) = 0;
		virtual void heapify_down(unsigned int n) = 0;

	public:
		Heap();
		Heap(const unsigned int max);
        // TODO: implement these...
        Heap(const Heap& that) = delete;
        Heap(const Heap&& that) = delete;

		void     insertNode(const HeapNode& node);
        void     deleteNode(unsigned int idx);
        HeapNode remove(unsigned int idx);

		// getters 
		unsigned int getNumElem(void) const;
        unsigned int getMaxSize(void) const;
        // More for debugging than anything...
        std::vector<HeapNode> getVector(void) const;
};

// Specialize into MinHeap and MaxHeap
/*
 * MinHeap
 */
class MinHeap : public Heap
{
    public:
        MinHeap();
        MinHeap(const unsigned int max);

    protected:
		void heapify_up(unsigned int n) override;
		void heapify_down(unsigned int n) override;
};

/*
 * MaxHeap
 */
class MaxHeap : public Heap
{
    public:
        MaxHeap();
        MaxHeap(const unsigned int max);

    protected:
		void heapify_up(unsigned int n) override;
		void heapify_down(unsigned int n) override;
};


// Jump around a heap array
unsigned int heap_parent(unsigned int idx);
unsigned int heap_left_child_idx(unsigned int idx);
unsigned int heap_right_child_idx(unsigned int idx);

// Util functions 
bool has_min_heap_property(const Heap& heap);
bool has_max_heap_property(const Heap& heap);

// 'private' functions
bool array_has_min_heap_property(const std::vector<HeapNode>& nodes, unsigned int idx);
bool array_has_max_heap_property(const std::vector<HeapNode>& nodes, unsigned int idx);

#endif /*__HEAP_HPP*/
