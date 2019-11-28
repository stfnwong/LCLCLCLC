/*
 * LIST
 * List stuff
 *
 * Stefan Wong 2019
 */

#ifndef __LC_LIST_HPP
#define __LC_LIST_HPP

#include <vector>

namespace lc_list
{

    struct ListNode
    {
        int val;
        ListNode* next;
        
        public:
            ListNode(int x) : val(x), next(nullptr) {} 
    };


    // Create a list from a vector
    ListNode* list_from_vector(const std::vector<int>& vals);
    void print_list_node(ListNode* root);
}


#endif /*__LC_LIST_HPP*/
