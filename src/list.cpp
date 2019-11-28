/*
 * LIST
 * List stuff
 *
 * Stefan Wong 2019
 */

#include <iostream>
#include "list.hpp"


namespace lc_list
{


ListNode* list_from_vector(const std::vector<int>& vals)
{
    ListNode* root;
    ListNode* dummy_head;

    std::cout << "[" << __func__ << "] creating new ListNode with " 
        << vals.size() << " elements." << std::endl;

    root = new ListNode(vals[0]);
    dummy_head = root;
    for(unsigned int n = 1; n < vals.size(); ++n)
    {
        dummy_head->next = new ListNode(vals[n]);
        dummy_head = dummy_head->next;
    }

    return root;
}


void print_list_node(ListNode* root)
{
    ListNode* dummy_root;

    dummy_root = root;
    std::cout << "[" << __func__ << "] list contents : " << std::endl << "{";
    while(dummy_root != nullptr)
    {
        std::cout << dummy_root->val << ",";
        dummy_root = dummy_root->next;
    }
    std::cout << "}" << std::endl;
}

}

