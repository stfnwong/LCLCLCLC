/*
 * LIST
 * List stuff
 *
 * Stefan Wong 2019
 */

#include <iostream>
#include "list.hpp"



void delete_list(ListNode* root)
{
    ListNode* cur_node;
    ListNode* next_node;
    
    if(!root)
        return;

    cur_node = root->next;
    while(cur_node)
    {
        if(cur_node->next)
        {
            next_node = cur_node->next;
            delete cur_node;
            cur_node = next_node;
        }
    }
}


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

ListNode* list_from_vector_with_tail_pointer(const std::vector<int>& vals, int tail_pointer_idx)
{
    ListNode* root = list_from_vector(vals);

    if(tail_pointer_idx >= 0)
    {
        // Make the next pointer of the tail element point to this pos
        int idx = 0;
        ListNode* target_pos;
        ListNode* cur_pos = root;

        while(cur_pos)
        {
            if(idx == tail_pointer_idx)
                target_pos = cur_pos;

            if(cur_pos->next == nullptr)
                break;
            cur_pos = cur_pos->next;
            idx++;
        }

        // cur_pos is now the tail node
        cur_pos->next = target_pos;
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



bool list_has_cycle(ListNode* root)
{
    if(root == nullptr || root->next == nullptr)
        return false;

    ListNode* fast_ptr = root;
    ListNode* slow_ptr = root;

    // Move the fast pointer ahead 
    while(fast_ptr != nullptr && fast_ptr->next != nullptr)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        // if we can catch ourselves, we have a cycle
        if(slow_ptr == fast_ptr)
            return true;
    }

    return false;
}

