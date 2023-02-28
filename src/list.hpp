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

// TODO: memory management
struct ListNode
{
    int val;
    ListNode* next;
    
    public:
        ListNode() : val(0), next(nullptr) {} 
        ListNode(int x) : val(x), next(nullptr) {} 
        ListNode(int x, ListNode* n) : val(x), next(n) {} 

        // TODO: write dtor that walks list and cleans up
};


// Create a list from a vector
ListNode* list_from_vector(const std::vector<int>& vals);
std::vector<int> vector_from_list(const ListNode* list);
unsigned list_length(ListNode* root);
void print_list_node(ListNode* root);


} //namespace lc_list


#endif /*__LC_LIST_HPP*/
