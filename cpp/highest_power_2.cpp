/*
Highest power of 2 less than or equal to given number

Given a number n, find the highest power of 2 that is smaller than or equal to n.
https://www.geeksforgeeks.org/highest-power-2-less-equal-given-number/
*/

#include <bits/stdc++.h>

int highest(unsigned int n)
{
    unsigned int count = 0;
    unsigned int res = 1;

    if (n < 1)
        return n;

    while(n > 1)
    {
        n >>= 1;
        count++;
        res <<= 1;
    }
    return res;
}

int main()
{
  unsigned int n = 32;
  printf("%d \n", highest(n));

  unsigned int m = 19;
  printf("%d \n", highest(m));

  return 0;
}
