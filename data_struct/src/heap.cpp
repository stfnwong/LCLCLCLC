/*
 * HEAP
 * Implementation stuff for heaps 
 */

#include "heap.hpp"


unsigned heap_parent(unsigned idx) 
{
    return idx / 2;
}
unsigned heap_left(unsigned idx)
{
    return (idx << 1) + 1;   // offset for zero-indexed heap
}
unsigned heap_right(unsigned idx)
{
    return (idx << 1) + 2;   // offset for zero-indexed heap
}
