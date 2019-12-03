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
int egg_drop(int num_floors, int num_eggs);


// ==== HANOI ===== //


#endif /*__LC_DYNAMIC_HPP*/
