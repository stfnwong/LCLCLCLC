/*
 * DYNAMIC
 * Dynamic Programming Practice
 *
 * Stefan Wong 2019
 */

#ifndef __LC_DYNAMIC_HPP
#define __LC_DYNAMIC_HPP

#include <vector>

// ==== FIBONACCI ===== //
int fibonacci(int i);
int fibonacci_memo(int i);
int fib_memo_inner(int i, std::vector<int>& memo);


// ======== Egg Drop (maximize minimum regret)
int egg_drop_2_eggs(int num_floors);
// TODO : version for any number of eggs


// ==== HANOI ===== //


#endif /*__LC_DYNAMIC_HPP*/
