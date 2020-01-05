/*
 * PALINDROME
 */

#include <stdint.h>
#include <string.h>

int is_palindrome_1(char* str, size_t len)
{
    for(size_t i = 0; i < (len / 2); ++i)
    {
        if(str[i] != str[len-i-1])
            return 0;
    }

    return 1;
}


// More complicated (and slower) implementation
// For one, we need to iterate twice since we call strlen() inside
// the function.
int is_palindrome_slow(char* str)
{
    int l, h;

    l = 0;
    h = strlen(str) - 1;

    while(h > l)
    {
        if(str[l] != str[h])
        {
            l++;
            h--;
            return 0;
        }
    }

    return 1;
}
