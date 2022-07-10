/*
it is guaranteed that array length is an odd number, and
there will always one unique int only
---
this can be solved using XOR

https://www.hackerrank.com/challenges/ctci-lonely-integer/problem
*/

#include <vector>

int lonely_integer(std::vector <int> a) 
{
    int res = 0;
    for (int x : a)
        res ^= x; // any int XOR'ed with it self will result 0
    return res;
}