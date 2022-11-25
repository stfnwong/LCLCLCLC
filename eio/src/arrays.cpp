/*
 * ARRAYS
 * Header for the arrays section of the datastructures module
 */

#include <algorithm>
#include <deque>
#include "arrays.hpp"


std::vector<int> find_max_sliding_window(const std::vector<int>& nums, unsigned int wsize)
{
    std::vector<int> result;

    if(nums.size() == 0)
        return result;

    // In cases where the window size is larger than the array size, we just consider 
    // the entire array as being under a window.
    if(wsize > nums.size())
        wsize = nums.size();

    // We implement the window as a deque which stores the elements in decreasing order.
    // The front of the deque contains the index for the maximum value in a particular
    // window. I use unsigned here as we are storing the index into nums and this will
    // shut the compiler up about type comparisons.
    std::deque<unsigned> window;

    // Find the maximum within the first window. The key idea here is that the deque
    // holds the index of the elements ordered by size. In this case
    // 
    // - The FRONT of the window queue holds the index of the LARGEST elements 
    // - The BACK of the window queue holds the index of the SMALLEST elements 
    //
    // Therefore, 
    // 1) If the current index is smaller than the index at the BACK of the queue, 
    // we push the current index to the back of the queue (where it becomes the new 
    // smallest element).
    //
    // 2) If the current element is larger than the element at the BACK of the queue
    // the the BACK is POPPED repeatedly until we find a higher value. After this we 
    // push the current index in as the new back.
    //
    // Each time the window moves to the right we repeat the following steps.
    // - Remove all elements from the back of the queue which are smaller than or equal
    // to the current element.
    // - If the element is no longer in the current window, remove the index of the 
    // element from the front of the queue.
    // - Push the current element index to the back of the queue.
    //

    for(unsigned i = 0; i < wsize; ++i)
    {
        // For every element, remove the previous smaller elements from the window
        // Recall that the BACK of this queue holds the SMALLEST elements
        while(!window.empty() && nums[i] >= nums[window.back()])
            window.pop_back();
        // If we get to here then this must be the element that we want to add
        window.push_back(i);
    }

    // The largest element in the window is the one whose index is found at the front 
    // of the queue (ie: its nums[window.front()])
    result.push_back(nums[window.front()]);

    return result;
}



bool is_palindrome(const std::string& input_string)
{
    int start = 0;
    int end = input_string.length()-1;
    //int end = std::max(0, input_string.length()-1);

    while(start < end)
    {
        if(input_string[start] != input_string[end])
            return false;
        start++;
        end--;
    }

    return true;
}

