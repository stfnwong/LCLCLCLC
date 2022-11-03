/*
 * HEAP
 * Implementation stuff for heaps 
 */

#include "heap.hpp"


unsigned max_heap_parent(unsigned idx) 
{
    return idx / 2;
}
unsigned max_heap_left(unsigned idx)
{
    return (idx << 1);
}
unsigned max_heap_right(unsigned idx)
{
    return (idx << 1) + 1;
}

