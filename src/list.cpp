/*
 * LIST
 * List stuff
 *
 * Stefan Wong 2019
 */

#include <iostream>
#include "list.hpp"


ListNode* list_from_vector(const std::vector<int>& vals)
{
    ListNode* root;
    ListNode* cur_node;

    if(vals.size() == 0)
        return nullptr;

    root = new ListNode(vals[0]);
    cur_node = root;
    for(unsigned int n = 1; n < vals.size(); ++n)
    {
        cur_node->next = new ListNode(vals[n]);
        cur_node = cur_node->next;
    }

    return root;
}

std::vector<int> vector_from_list(const ListNode* node)
{
    std::vector<int> out_vec;

    if(node == nullptr)
        return out_vec;

    while(node != nullptr)
    {
        out_vec.push_back(node->val);
        node = node->next;
    }

    return out_vec;
}


unsigned list_length(ListNode* root)
{
    unsigned len = 0;
    
    if(!root)
        return len;

    while(root)
    {
        len++;
        root = root->next;
    }

    return len;
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


