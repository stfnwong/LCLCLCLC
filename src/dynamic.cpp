/*
 * DYNAMIC
 * Dynamic Programming Practice
 *
 * Stefan Wong 2019
 */

#include <algorithm>
#include <iostream>
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
    fib_memo_inner(i, memo);
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




// ======== Egg Drop (maximize minimum regret)
int egg_drop(int num_floors, int num_eggs)
{
    int num_drops;
    int min;
    // If we derive the max of min regret then we can in fact solve 
    // this directly as n * (n+1) / 2 >= num_floors

    // DEBUG output
    std::cout << "[" << __func__ << "] computing e=" 
        << num_eggs << " and f=" << num_floors << std::endl;

    // No need to drop from small buildings
    // if we only have one egg, then we have no choice but to start at 
    // the bottom and keep dropping from a floor one higher each time.
    if(num_floors == 0 || num_floors == 1)
        return num_floors;

    if(num_eggs == 1)
    {
        std::cout << "[" << __func__ << "] only have one egg left" << std::endl;
        return num_floors;
    }

    std::cout << "[" << __func__ << "] testing up to " << num_floors << " more floors" << std::endl;
    min = num_floors + 1;
    for(int k = 1; k <= num_floors; ++k)
    {
        // we need to maximum minimum regret here
        num_drops = std::max(
                egg_drop(num_floors - 1, num_eggs-1), // egg breaks
                egg_drop(num_floors - k, num_eggs)    // egg doesn't break
        );
        if(num_drops < min)
            min = num_drops;
    }

    return min + 1;
}
