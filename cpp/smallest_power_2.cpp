/*
Smallest power of 2 greater than or equal to n
Write a function that, for a given no n, finds a number p which is greater than or equal to n and is a smallest power of 2. 
https://www.geeksforgeeks.org/smallest-power-of-2-greater-than-or-equal-to-n/
*/

#include <bits/stdc++.h>

int nextPowerOf2(unsigned int n)
{
    unsigned int count = 0;

    if (n < 1)
        return n;

    while(n != 0)
    {
        n >>= 1;
        count++;
    }
    return pow(2,count);
}

int main()
{
  unsigned int n = 17;
  printf("%d", nextPowerOf2(n));
  return 0;
}
