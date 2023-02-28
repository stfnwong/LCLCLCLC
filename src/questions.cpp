/*
 * QUESTIONS
 * Solutions to specific Leetcode questions
 *
 * Stefan Wong 2019
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>

#include "questions.hpp"

/*
 * Question 1
 * https://leetcode.com/problems/two-sum/
 *
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */
std::vector<int> two_sum_map(std::vector<int>& nums, int target)
{
    std::vector<int> output(2);
    // why use a map here...
    std::unordered_map<int, int> diff_map;

    for(unsigned int n = 0; n < nums.size(); ++n)
    {
        int diff = target - nums[n];
        if(diff_map.count(diff) > 0)
        {
            //std::cout << "[" << __func__ << "] found key " << diff << std::endl;
            output[0] = diff_map[diff];
            output[1] = n;
            return output;
        }

        // add new differences to map
        diff_map.insert({nums[n], n});
    }

    return output;
}

//
// two sum sorted pointer
std::vector<int> two_sum_sort_and_pointer(std::vector<int>& nums, int target)
{
    int n = int(nums.size());
    std::vector<std::pair<int, int>> val_and_idx(n);

    // since we plan to sort the array we need to remember what the original index was 
    // create a vector of pairs that store a value and its position in the original array 
    for(int i = 0; i < n; ++i)
        val_and_idx[i] = std::make_pair(nums[i], i);

    // now we can sort the input 
    std::sort(val_and_idx.begin(), val_and_idx.end());
    int left = 0;
    int right = val_and_idx.size()-1;
    //int right = n-1;

    while(left < right) 
    {
        int s = val_and_idx[left].first + val_and_idx[right].first;
        std::cout << "[" << __func__ << "] left  (" << left << "): " << val_and_idx[left].first << std::endl;
        std::cout << "[" << __func__ << "] right (" << right << "): " << val_and_idx[right].first << std::endl;
        std::cout << "[" << __func__ << "] s: " << std::left << std::setw(4) << s << std::endl;
        if(s == target)
            return std::vector<int>{val_and_idx[left].second, val_and_idx[right].second};
        else if(s > target)
            right--;    //  too large, deccrease 
        else
            left++;     // too small, increase
    }

    // cant find anything
    return std::vector<int>{};

}

// two sum brute force 
std::vector<int> two_sum_brute_force(std::vector<int>& nums, int target)
{
    for(int i = 0; i < int(nums.size()); ++i)
    {
        for(int j = i+1; j < int(nums.size()); ++j)
        {
            int s = nums[i] + nums[j];
            if(s == target)
                return std::vector<int>{i, j};
        }
    }

    // in the real question I think we are guaranteed there is an answer 
    return std::vector<int>{};  
}

/*
 * Question 2
 */
ListNode* add_two_numbers(ListNode* l1, ListNode* l2)
{
    int sum;
    int carry;
    ListNode* output;
    ListNode* root;

    // map pointers to the input lists 
    ListNode* p = l1;
    ListNode* q = l2;

    carry = 0;
    root = new ListNode(0);
    output = root;

    //int q_val;
    //int p_val;

    while(p != nullptr || q != nullptr)
    {
        if(p != nullptr)
        {
            sum = sum + p->val;
            p = p->next;
        }
        if(q != nullptr)
        {
            sum = sum + q->val;
            q = q->next;
        }
        sum = sum + carry;
        carry = sum / 10;
        output->next = new ListNode(sum % 10);
        output = output->next;
    }

    if(carry > 0)
        output->next = new ListNode(carry);     // 'remainder' (but since list is reversed, its actually overflow)

    return root->next;    // ignore the first node - its just a dummy for init purposes
}


/*
 * Question 3
 */
int length_of_longest_substring(std::string& s)
{
    unsigned int start = 0;
    unsigned int end = 0;
    int max_ever = 0;
    std::unordered_map <char, bool> seen_chars;


    // Create a sliding window and walk along the string. 
    while(end < s.size())
    {
        // add new characters to the map and move the pointer forward
        if(seen_chars.count(s[end]) == 0)
        {
            seen_chars.insert( {s[end], true} );
            end++;
            max_ever = std::max(max_ever, (int) seen_chars.size());
        }
        else
        {
            // this character has been seen before
            seen_chars.erase(s[start]);
            start++;
        }
    }

    return max_ever;
}


/*
 * Question 14
   https://leetcode.com/problems/longest-common-prefix/

   Write a function to find the longest common prefix amongst an array of strings. If
   there is no common prefix, return an empty string.

    Example:
    input: strs = ["flower", "flow", "flight"]
    output = "fl"
 */
std::string longest_common_prefix(std::vector<std::string>& strs)
{
    unsigned int max_prefix;
    std::string prefix;

    prefix = "";
    max_prefix = 9999999;

    // find the maximum length we could possibly need
    for(unsigned int s = 0; s < strs.size(); ++s)
    {
        if(strs[s].size() < max_prefix)
            max_prefix = strs[s].size();
    }

    // 'Vertically' scan over the strings and compare them with strs[0]
    for(unsigned int c = 0; c < max_prefix; ++c)
    {
        // check each string in turn
        for(unsigned int s = 1; s < strs.size(); ++s)
        {
            if(strs[0][c] != strs[s][c])
                return prefix;
        }
        prefix = prefix + strs[0][c];
    }

    return prefix;
}

/*
 * Question 14 again
 */

bool is_common_prefix(std::vector<std::string>& strs, unsigned int max_len)
{
    std::string ref_string = strs[0].substr(0, max_len);

    for(unsigned int c = 0; c < max_len; ++c)
    {
        for(unsigned int s = 1; s < strs.size(); ++s)
        {
            if(strs[s][c] != ref_string[c])
                return false;
        }
    }

    return true;
}




std::string longest_common_prefix_binary_search(std::vector<std::string>& strs)
{
    unsigned int min_len = 99998;
    std::string prefix = "";
    int low, high, mid;

    // if there are no strings, then we are done here
    if(strs.size() == 0)
        return prefix;

    // find the length of the shortest string
    for(unsigned int s = 0; s < strs.size(); ++s)
    {
        if(strs[s].size() < min_len)
            min_len = strs[s].size();
    }

    low = 0;
    high = min_len;
    while(low <= high)
    {
        std::cout << "[" << __func__ << "] low : " << low << " high : " << high << std::endl;
        mid = (high + low) / 2;
        if(is_common_prefix(strs, mid))
            low = mid + 1;      // all the characters below match (ignore)
        else
            high = mid - 1;     // none of the characters above match
    }
    // The prefix lies at the midpoint of low and high
    prefix = strs[0].substr(0, (low + high) / 2);

    return prefix;
}




/*
 * Question 17
 */

// recursive helper function
// TODO: what would the iterative version of this look like?
void find_letter_combo(
        std::string& digits,
        std::vector<std::string>& output,
        std::unordered_map<char, std::string> mapping,
        std::string cur_string,
        unsigned int idx)
{
    if(idx == digits.size())
    {
        output.push_back(cur_string);
        return;
    }

    std::string substr = mapping[digits[idx]];
    for(unsigned int c = 0; c < substr.size(); ++c)
    {
        find_letter_combo(digits, output, mapping, cur_string + substr[c], idx+1);
    }
}

std::vector<std::string> letter_combinations_17(std::string digits)
{
    std::vector<std::string> output;

    if(digits.size() == 0)
        return output;

    std::unordered_map<char, std::string> digit_map = {
        {'0', "0"},
        {'1', "1"},
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    find_letter_combo(digits, output, digit_map, std::string(""), 0);
    
    return output;
}



/*
 * Question 18
 */
//std::vector<std::vector<int>> four_sum(std::vector<int>& nums, int target)
//{
//    
//}


/*
 * Question 21
 * Merge two sorted lists
 * https://leetcode.com/problems/merge-two-sorted-lists
 */
ListNode* merge_two_sorted_lists_21(ListNode* list1, ListNode* list2)
{
    if(list1 == nullptr && list2 == nullptr)
        return nullptr;


    //ListNode* out_list = new ListNode();
    ListNode* out_list = nullptr;
    ListNode* out_list_tail = out_list;

    while(list1 != nullptr || list2 != nullptr)
    {
        ListNode* cur_node = new ListNode();
        if(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val < list2->val)
            {
                cur_node->val = list1->val;
                list1 = list1->next;
            }
            else
            {
                cur_node->val = list2->val;
                list2 = list2->next;
            }
        }
        else if(list1 != nullptr)
        {
            cur_node->val = list1->val;
            list1 = list1->next;
        }
        else 
        {
            cur_node->val = list2->val;
            list2 = list2->next;
        }

        // add cur_node to end of out list
        if(out_list == nullptr)
        {
            out_list = cur_node;
            out_list_tail = out_list;
        }
        else
        {
            out_list_tail->next = cur_node;
            out_list_tail = out_list_tail->next;
        }
    }

    return out_list;
}


/*
 * Question 23
 * Merge k sorted lists 
 * https://leetcode.com/problems/merge-k-sorted-lists
 */
ListNode* merge_k_sorted_lists_23(const std::vector<ListNode*>& lists)
{
    if(lists.size() == 0)
        return nullptr;

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    ListNode* head;

    // iterate over each list and push elements into queue
    for(unsigned l = 0; l < lists.size(); ++l)
    {
        head = lists[l];
        while(head)
        {
            pq.push(head->val);
            head = head->next;
        }
    }

    // Now we have a heap with all elements inside 
    if(pq.empty())
        return nullptr;    // all lists were empty

    ListNode* out_list = nullptr;
    ListNode* out_list_head;
    out_list_head = out_list;

    while(!pq.empty())
    {
        ListNode* cur_node = new ListNode();
        cur_node->val = pq.top();
        pq.pop();

        // attach to out list 
        if(out_list == nullptr)
        {
            out_list = cur_node;
            out_list_head = out_list;
        }
        else
        {
            out_list_head->next = cur_node;
            out_list_head = cur_node;
        }
    }

    return out_list;
}




/*
 * Question 49
 * Trapping rainwater
 * https://leetcode.com/problems/trapping-rain-water/
 */


/*
 * Question 42
 * Trapping rainwater
 * https://leetcode.com/problems/trapping-rain-water/
 */
// TODO: there are several ways to approach this, implement several of them here
int trapping_rain_water_42(const std::vector<int>& height) 
{
    unsigned N = height.size();
    std::vector<int> lmax(N);
    std::vector<int> rmax(N);
    int cur_max;

    if(height.size() < 3)
        return 0;           // not enough blocks to trap any water

    // Find max height from the left 
    lmax[0] = height[0];
    for(unsigned i = 1; i < N; ++i)
        lmax[i] = std::max(lmax[i-1], height[i-1]);

    rmax[N-1] = height[N-1];
    for(int i = N-2; i >= 0; --i)   // NOTE: don't use unsigned for decrement
        rmax[i] = std::max(rmax[i+1], height[i+1]);
    
    int ans = 0;
    for(unsigned i = 0; i < N; ++i)
    {
        int level = std::min(lmax[i], rmax[i]);
        if(level >= height[i])
            ans += level - height[i];
    }

    return ans;
}

// Alternative solution with two pointers
// Time: O(N)
// Space: O(1)
// 
// I still don't quite grasp the intuition for how this method works for this problem...
int trapping_rain_water_42_two_pointers(const std::vector<int>& height) 
{
    if(height.size() < 2)
        return 0;

    // NOTE: making these int (rather than unsigned) is probably sufficient for this, 
    // but if we wanted to use unsigned here then we need to check for underflow in the 
    // decrement branch
    unsigned lptr = 0;
    unsigned rptr = height.size()-1;
    int ans = 0;
    int min_h = 0;
    int max_h = 0;

    while(lptr < rptr)
    {
        min_h = std::min(height[lptr], height[rptr]);
        max_h = std::max(max_h, min_h);
        ans += max_h - min_h;   // TODO: why does this work?

        if(height[lptr] < height[rptr])
            lptr++;
        else
            rptr = ((rptr-1) >= std::numeric_limits<unsigned>::max()-1) ? 0 : rptr-1;
    }

    return ans;
}



/*
 * Question 49
 * Group Anagrams 
 * https://leetcode.com/problems/group-anagrams
 */
// NOTE: can sort the letters, this makes all anagrams the same
std::vector<std::vector<std::string>> group_anagrams_49(const std::vector<std::string>& strs)
{
    std::unordered_map<std::string, std::vector<std::string>> anagrams;

    for(std::string s : strs)
    {
        std::string cur_string = s;
        std::sort(cur_string.begin(), cur_string.end());
        anagrams[cur_string].push_back(s);
    }

    std::vector<std::vector<std::string>> ans;

    for(std::pair<std::string, std::vector<std::string>> group: anagrams)
        ans.push_back(group.second);

    return ans;
}


/*
 * Question 55
 */
// Lets implement the dumb way here. 

bool can_jump_here_basic(int cur_pos, std::vector<int>& nums)
{
    if(cur_pos == (int) nums.size()-1)
        return true;

    int max_jump;
    if((cur_pos + nums[cur_pos]) > (int) nums.size()-1)
        max_jump = nums.size()-1;
    else
        max_jump = cur_pos + nums[cur_pos];

    for(int next_pos = cur_pos+1; next_pos <= max_jump; ++next_pos)
    {
        //std::cout << "[" << __func__ << "] jumping from " << 
        //    cur_pos << "->" << next_pos << std::endl;
        if(can_jump_here_basic(next_pos, nums))
            return true;
    }

    return false;
}

bool can_jump(std::vector<int>& nums)
{
    return can_jump_here_basic(0, nums);
}



/*
 * Question 66
 * Plus One
 * https://leetcode.com/problems/plus-one
 */
std::vector<int> plus_one_66(std::vector<int>& digits)
{
    // only edge case is if the digits are all nines, in which case we need to 
    // extend the vector by one to account for the carry.
    bool all_nines = true;
    for(int x: digits) 
    {
        if(x != 9) 
        {
            all_nines = false;
            break;
        }
    }

    if(all_nines) 
    {
        digits.insert(digits.begin(), 0);
        for(int& x: digits)
            x = 0;
        digits[0] = 1;
    }
    else 
    {
        for(unsigned i = digits.size()-1; i >= 0; --i) 
        {
            digits[i]++;
            // overflow/carry for this column
            if(digits[i] == 10)  
                digits[i] = 0;
            else
                break;   // we managed to add a one, no need to continue
        }
    }

    return digits;
}


/*
 * Question 102
 * Binary Tree Level Order Traversal
 * https://leetcode.com/problems/binary-tree-level-order-traversal/
 */
std::vector<std::vector<int>> level_order_traversal_102(const TreeNode* root)
{
    if(not root)
        return std::vector<std::vector<int>>();

    std::queue<TreeNode*> node_q;
    std::vector<std::vector<int>> traversal;

    node_q.push(new TreeNode(*root));
    while(!node_q.empty())
    {
        std::vector<int> level;
        unsigned num_nodes = node_q.size();
        for(unsigned i = 0; i < num_nodes; ++i)
        {
            TreeNode* cur_node = node_q.front();
            level.push_back(cur_node->val);
            if(cur_node->left)
                node_q.push(cur_node->left);
            if(cur_node->right)
                node_q.push(cur_node->right);

            node_q.pop();
        }

        traversal.push_back(level);
    }

    return traversal;
}


/*
 * Question 111 
https://leetcode.com/problems/minimum-depth-of-binary-tree/
Minimum depth of binary tree
*/
int min_depth_of_binary_tree_111(const TreeNode* root)
{
    if(!root)
        return 0;

    unsigned height = 0;

    std::queue<const TreeNode*> node_q;
    node_q.push(root);

    while(!node_q.empty())
    {
        unsigned num_nodes = node_q.size();
        height++;

        for(unsigned i = 0; i < num_nodes; ++i)
        {
            const TreeNode* cur_node = node_q.front();
            if(!cur_node || (!cur_node->left && !cur_node->right))
                return height;

            if(cur_node->left)
                node_q.push(cur_node->left);
            if(cur_node->right)
                node_q.push(cur_node->right);

            node_q.pop();
        }
    }

    return height;
}

 /*
  * Question 114
  * https://leetcode.com/problems/path-sum-ii/description/
  */
void path_sum_ii_dfs_helper(
        const TreeNode* node, 
        std::vector<int>& path,
        std::vector<std::vector<int>>& valid_paths,
        int cur_sum,
        int target_sum
        )
{
    if(node)
    {
        path.push_back(node->val);
        cur_sum += node->val;


        // check that this is a child node 
        if(!node->left && !node->right)
        {
            if(cur_sum == target_sum)
                valid_paths.push_back(path);
        }
        else
        {
            path_sum_ii_dfs_helper(node->left, path, valid_paths, cur_sum, target_sum);
            path_sum_ii_dfs_helper(node->right, path, valid_paths, cur_sum, target_sum);
        }
    }
}

std::vector<std::vector<int>> path_sum_ii_113(const TreeNode* root, int target_sum)
{
    std::vector<std::vector<int>> results;
    
    if(!root)
        return results;

    // the recursive dfs solution 
    std::vector<int> paths;
    path_sum_ii_dfs_helper(root, paths, results, 0, target_sum);

    return results;
}

// TODO: iterative DFS?


// Another (iterative) BFS implementation 
std::vector<std::vector<int>> path_sum_ii_113_bfs_iter(const TreeNode* root, int target_sum)
{
    std::vector<std::vector<int>> results;

    if(!root)
        return results;

    using NodePath = std::pair<const TreeNode*, std::vector<int>>; 

    //std::queue<NodePath> node_q;
    std::deque<NodePath> node_q;
    std::vector<int> cur_path;

    cur_path.push_back(root->val);
    node_q.push_back({root, cur_path});   // TODO: does it need to be a deque?

    while(!node_q.empty())
    {
        NodePath np = node_q.front();
        const TreeNode* cur_node = np.first;
        std::vector<int> cur_path = np.second;
        node_q.pop_front();

        // Check if this is a leaf node 
        if(!cur_node->left && !cur_node->right)
        {
            int s = std::reduce(cur_path.begin(), cur_path.end());
            std::cout << "Sum: " << s << std::endl;
            if(s == target_sum)
            {
                std::vector<int> v = cur_path;
                results.push_back(v);
                std::cout << "results.size() = " << results.size() << std::endl;
            }
        }

        std::vector<int> new_vec = cur_path;
        if(cur_node->left)
        {
            new_vec.push_back(cur_node->left->val);
            NodePath new_node_path = {cur_node->left, new_vec};
            node_q.push_back(new_node_path);
        }
            
        if(cur_node->right)
        {
            new_vec.push_back(cur_node->right->val);
            NodePath new_node_path = {cur_node->right, new_vec};
            node_q.push_back(new_node_path);
        }

    }

    return results;
}



///std::vector<std::vector<int>> path_sum_ii_113_bfs_iter(const TreeNode* root, int target_sum)
///{
///    std::vector<std::vector<int>> results;
///
///    if(!root)
///        return results;
///
///    std::queue<const TreeNode*> node_q;
///    std::vector<int> cur_path;
///
///    cur_path.push_back(root->val);
///
///    while(!node_q.empty())
///    {
///        const TreeNode* cur_node = node_q.front();
///        // Check if this is a leaf node 
///        if(!cur_node->left && !cur_node->right)
///        {
///            if(std::reduce(cur_path.begin(), cur_path.end()))
///                results.push_back(cur_path);
///        }
///
///
///        node_q.pop();
///        if(cur_node->left)
///            node_q.push(cur_node->left);
///    }
///
///    return results;
///}
///

//def test_min_depth_binary_tree_111():
//    inputs = [
//        "[3,9,20,null,null,15,7]",
//        "[2,null,3,null,4,null,5,null,6]"
//    ]
//    exp_outputs = [2, 5]
//    functions = [questions.min_depth_111]
//
//    for func in functions:
//        for inp, exp_out in zip(inputs, exp_outputs):
//            tree = repr_to_tree(inp)
//            depth = func(tree)
//            assert depth == exp_out
//

// ==== Question 153
// Find minimum in rotated sorted array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
int find_min_in_rotated_sorted_array(const std::vector<int>& nums)
{
    // check if array is not rotated 
    if(nums[0] <= nums[nums.size()-1])
        return nums[0];

    int l = 0;
    int r = int(nums.size());

    while(l < r) 
    {
        int p = (l + r) / 2;
        if(nums[p] >= nums[0])
            l = p + 1;
        else
            r = p;
    }

    return nums[l];
}

// ==== Question 155
// Min stack
// https://leetcode.com/problems/min-stack
// (Solution in header file)

// ==== Question 198
// https://leetcode.com/problems/house-robber/
int house_robber_198(const std::vector<int>& nums)
{
    if(nums.size() == 0)
        return 0;

    if(nums.size() < 3)
        return *std::max_element(nums.begin(), nums.end());

    std::vector<int> dp(nums.size());
    dp[0] = nums[0];
    dp[1] = nums[1];

    for(unsigned i = 2; i < dp.size(); ++i)
        dp[i] = std::max(nums[i] + dp[i-2], dp[i-1]);

    return dp.back();
}


/*
 Question 239
 https://leetcode.com/problems/sliding-window-maximum/
 Maximum in sliding window 
*/
std::vector<int> max_sliding_window_239_deque(const std::vector<int>& nums, int wsize) 
{
    std::vector<int> result;
    if(nums.size() == 0)
        return result;

    // Deque to store indicies into the input array, sorted by value. 
    // Specifically - the value at the front of the deque is the index of the value in 
    // nums which is the largest in the current window.
    //
    // To main this order without "sorting" we check the value of each element as we
    // place it into the deque. We do this by checking each new element we visit in
    // nums. Note that the order we want to preserve is 
    //
    // [idx_of_largest_value, idx_of_next_smallest_value, ..., idx_of_smallest_value]
    //
    // - If the current element is smaller than the element whose index is at the back 
    // of the deque the we push the index of that element to the back.
    // - If the current element is larger that the back of the deque then we pop the 
    // back of the deque until we find a higher value. Then we push the current value
    // to the back. This has the effect of popping every value smaller than the 
    // current value from the back, leaving the current value as the new minimum value.
    //
    //
    std::deque<unsigned> idx_q;

    for(unsigned idx = 0; idx < nums.size() - wsize; ++idx)
    {

    }

    return result;
}

/*
Question 322
https://leetcode.com/problems/coin-change/
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin
 */
int coin_change_vec_322(std::vector<int>& coins, int amount)
{
    // Time complexity: O(AC)
    // Space complexity: O(A)

    int MAX_COST = amount + 1;
    std::vector<int> min_num_coins(amount+1);

    min_num_coins[0] = 0;

    for(unsigned n = 1; n < min_num_coins.size(); ++n)
        min_num_coins[n] = amount + 1;

    // the nth element of min_num_coins represents the minimum number of coins to sum to n
    for(unsigned n = 1; n <= min_num_coins.size(); ++n)
    {
        for(unsigned c = 0; c < coins.size(); ++c)
        {
            // If the difference between n and coins[c] is positive, it means that 
            // coins[c] could be used as part of the solution.
            if((n - coins[c]) >= 0)
                min_num_coins[n] = std::min(min_num_coins[n], 1 + min_num_coins[n - coins[c]]);
        }
    }

    if(min_num_coins[amount] < (amount + 1))
        return min_num_coins[amount];

    return -1;
}

// TODO: BFS solution with memo


/*
 Question 337
 https://leetcode.com/problems/house-robber-iii
 House Robber III

*/
std::pair<int, int> hr3_dp(TreeNode* root)
{
}

int house_robber_iii_337(TreeNode* root)
{
}



/*
 * Question 842
 * Split array into Fibonacci like sequence
 */
//std::vector<int> split_into_fib_seq_842(int i)
//{
//}



/*
 Question 929
 Unique Email Addresss
 https://leetcode.com/problems/unique-email-addresses
*/
int num_unique_emails_929(const std::vector<std::string>& emails)
{
}

/*
 Question 994
 Rotting Oranges
 https://leetcode.com/problems/rotting-oranges/
*/





/*
 Question 1046
 Last Stone Weight
 https://leetcode.com/problems/last-stone-weight/
*/
int last_stone_weight_1046(std::vector<int>& stones)
{
    std::priority_queue<int> s(stones.begin(), stones.end());

    while(s.size() > 1)
    {
        int y = s.top();
        s.pop();
        int x = s.top();
        s.pop();

        if(x != y)
            s.push(y - x);
    }

    return s.size() > 0 ? s.top() : 0;
}

/*
 Question 1049
 Last Stone Weight II
 https://leetcode.com/problems/last-stone-weight-ii/
*/
int last_stone_weight_ii_1049(std::vector<int>& stones)
{
    if(stones.size() == 1)
        return  stones[0];

    std::priority_queue<int> s(stones.begin(), stones.end());

    while(s.size() > 1)
    {
        int y = s.top();
        s.pop();
        int x = s.top();
        s.pop();
        if(x != y)
            s.push(y - x);
    }

    return s.size() > 0 ? s.top() : 0;
}

/*
 * Question 1222
 * Queens that can attack a King
 */

// helper function to ensure that this row, col pair lies on the board
bool is_inside(int row, int col)
{
    if(row >= 0 && row <= 7 && col >= 0 && col <= 7)
        return true;

    return false;
}

std::vector<std::vector<int>> queensAttackTheKing(std::vector<std::vector<int>>& queens, std::vector<int>& king) 
{
    int row, col;
    std::vector<std::vector<bool>> has_queen(8, std::vector<bool>(8));
    std::vector<std::vector<int>> output;

    // populate the vector that tells us if we have a queen
    for(std::vector<int> q : queens)
    {
        has_queen[q[0]][q[1]] = true;
    }
    
    // walk over the board in delta co-ordinates 
    for(int d1 = -1; d1 <=1; d1++)
    {
        for(int d2 = -1; d2 <= 1; d2++)
        {
            if(d1 == 0 && d2 == 0)
                continue;
            // we know that the kind vector is a 2-tuple
            row = king[0];
            col = king[1];
            do{
                row += d1;
                col += d2;
            } while(is_inside(row, col) && !has_queen[row][col]);

            // Getting we stop here if we are outside the board or there was
            // a queen. Therefore if we test if we are inside then there must
            // not have been a queen here.
            if(is_inside(row, col))
            {
                output.push_back({row, col});       // didn't realise this syntax was legal
            }
        }
    }

    return output;
}

// ==== QUESTION 1143
// https://leetcode.com/problems/longest-common-subsequence/
// This solution is okay (memoization brings time complexity down to 
int longest_common_subsequence_1143(const std::string& text1, const std::string& text2)
{
    if(text1.empty() || text2.empty())
        return 0;

    using text_pair = std::pair<std::string, std::string>;
    std::map<text_pair, int> answer;

    auto it = answer.find({text1, text2});
    if(it != answer.end())
        return it->second;

    // Actually we only have to check 


}

// Question 1971
// https://leetcode.com/problems/find-if-path-exists-in-graph/submissions/
//Solution_1971::Solution_1971(int n, int source, int dest) : source(source), dest(dest)
//{
//    this->adj = std::vector<int>[n];
//    this->vis = std::vector<bool>(n);
//}
//
//bool Solution_1971::dfs(int node_key)
//{
//    if(node_key == this->dest)
//        return true;
//
//    this->vis[node_key] = true;
//    for(unsigned idx = 0; idx < this->adj[node_key].size(); ++idx)
//    {
//        auto v = this->adj[node_key][v];
//        if(!this->vis[v])
//            this->dfs(v);
//    }
//
//    return false;
//}
//
//bool Solution_1971::valid_path(int n, const std::vector<std::vector<int>>& edges, int source, int dest)
//{
//    this->dest = dest;
//    this->source = source;
//    std::vector<int> adj[n];
//
//    // Create adjaceny list 
//    for(unsigned i = 0; i < edges.size(); ++i)
//    {
//        adj[edges[i][0]].push_back(edges[i][1]);
//        adj[edges[i][1]].push_back(edges[i][0]);
//    }
//    
//    return this->dfs(this->source);
//}


// TODO: an iterative solution
