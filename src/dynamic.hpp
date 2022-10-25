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
int fib_iter(int i);



// ==== HANOI ===== //

#endif /*__LC_DYNAMIC_HPP*/
