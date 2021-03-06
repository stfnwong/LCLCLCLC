/*
 * DYNAMIC
 * Dynamic Programming Practice
 *
 * Stefan Wong 2019
 */

#include "dynamic.hpp"


int fibonacci(int i)
{
    if(i == 0 || i == 1)
        return i;
    
    return fibonacci(i - 1) + fibonacci(i - 2);
}


// Top down implementation
int fibonacci_memo(int i)
{
    std::vector<int> memo(i+1, 0);
    // init the bottom cases
    memo[0] = 0;
    memo[1] = 0;
    return fib_memo_inner(i, memo);
    //fib_memo_inner(i, std::vector<int> memo(i + 1));
}

int fib_memo_inner(int i, std::vector<int>& memo)
{
    if(i == 0 || i == 1)
        return i;

    if(memo[i] == 0)
        memo[i] = fib_memo_inner(i - 1, memo) + fib_memo_inner(i - 2, memo);

    return memo[i];
}

// Bottom up implementation
