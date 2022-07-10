#include <unordered_map>

using namespace std;

/*
https://www.hackerrank.com/challenges/ctci-recursive-staircase/problem

this problem quite similar to fibonacci
use preinitialize cache in recursion
*/

unordered_map<int, int> cache({
                                {1,1},
                                {2,2},
                                {3,4}
                            });

int climb(int n)
{
    if (n < 0)
        return 0;

    if (cache.find(n) != cache.end())
        return cache[n];
    
    int ret = n;
    if (n >= 3)
    {
        ret = climb(n - 1);
        ret += climb(n - 2);
        ret += climb(n - 3);
    }
    cache.insert(make_pair(n, ret));
    return ret;
}