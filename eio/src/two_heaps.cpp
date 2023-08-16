/*
 * Examples of the two-heaps technique 
 */


#include <algorithm>
#include <functional>

#include "two_heaps.hpp"


std::vector<int> maximum_capital(int c, int k, const std::vector<int>& capitals, const std::vector<int>& profits)
{
    std::vector<int> capital_min_heap;

    // Heapify this vector 
    std::make_heap(capital_min_heap.begin(), capital_min_heap.end(), std::greater());

    // Now insert the capital requirements for each project into the heap 
    for(unsigned i = 0; i < capitals.size(); ++i)
    {
        capitals_min_heap.push_back(capitals[i]);
        std::push_heap(capitals_min_heap.begin(), capitals_min_heap.end(), std::greater());
    }

    return capital_min_heap;
}
